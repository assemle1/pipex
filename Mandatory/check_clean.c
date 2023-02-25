/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:05:42 by astalha           #+#    #+#             */
/*   Updated: 2023/02/25 11:14:47 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freealloc2(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr[i])
		i++;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free(ptr);
}

int	errchecker(t_infos *infos)
{
	if (!infos->paths1 || !infos->paths2)
		return (ft_putstr_fd("bash : no path in env\n", 2), 0);
	if (!infos->cmd1 || !infos->cmd2)
		return (ft_putstr_fd("Syntaxe Error\n", 2), 0);
	if (!infos->cmd1[0] || !infos->cmd2[0])
		ft_putstr_fd("bash : command not found\n", 2);
	return (1);
}

void	free_all(t_infos *infos)
{
	if (infos->cmd1)
		freealloc2(infos->cmd1);
	if (infos->cmd2)
		freealloc2(infos->cmd2);
}

void	close_all(t_infos *infos)
{
	close(infos->fd[0]);
	close(infos->fd[1]);
	close(infos->infile);
	close(infos->outfile);
}

void	fill_infos(t_infos *infos, char **av, char **env)
{
	infos->paths1 = get_path(env);
	infos->paths2 = get_path(env);
	infos->cmd1 = ft_split(av[2], ' ');
	infos->cmd2 = ft_split(av[3], ' ');
	infos->cmd1[0] = get_cmd(infos->cmd1[0], infos->paths1);
	infos->cmd2[0] = get_cmd(infos->cmd2[0], infos->paths2);
	if (!errchecker(infos))
	{
		free_all(infos);
		close_all(infos);
		exit(1);
	}
}
