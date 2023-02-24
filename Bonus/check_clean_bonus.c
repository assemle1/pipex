/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clean_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:05:42 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:39 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	errchecker(t_infos *infos, int ac)
{
	int	i;

	i = 0;
	if (!infos->paths)
		return (ft_putstr_fd("bash : no path in env\n", 2), 0);
	while (i < ac - 3)
	{
		if (!infos->cmds[i])
			return (ft_putstr_fd("Syntaxe Error\n", 2), 0);
		if (!infos->cmds[i][0])
			return (ft_putstr_fd("bash : command not found\n", 2), 0);
			i++;
	}
	return (1);
}

void	free_all(t_infos *infos)
{
	int	i;

	i = 0;
	while (infos->cmds[i])
	{
		if (infos->cmds[i])
			freealloc2(infos->cmds[i]);
		i++;
	}
	free(infos->cmds);
}

void	close_all(int fd1, int fd2, t_infos *infos)
{
	close(fd1);
	close(fd2);
	close(infos->fd[0]);
	close(infos->fd[1]);
}

void	fill_infos(t_infos *infos, char **av, int ac)
{
	int	i;

	i = 0;
	infos->cmds = malloc((ac - 2) * sizeof(char **));
	if (!infos->cmds)
		return ;
	while (i < ac - 3)
	{
	infos->paths = get_path(infos->env);
	infos->cmds[i] = ft_split(av[i + 2], ' ');
	infos->cmds[i][0] = get_cmd(infos->cmds[i][0], infos->paths);
	i++;
	}
	infos->cmds[i] = NULL;
	if (!errchecker(infos, ac))
	{
		free_all(infos);
		close_all(infos->infile, infos->outfile, infos);
		exit(1);
	}
}
