/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:26:29 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 22:48:21 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1(t_infos *infos, char **env)
{
	dup2(infos->infile, STDIN_FILENO);
	dup2(infos->fd[1], 1);
	close_all(infos);
	execve(infos->cmd1[0], infos->cmd1, env);
}

void	cmd2(t_infos	*infos, char	**env)
{
	dup2(infos->outfile, STDOUT_FILENO);
	dup2(infos->fd[0], 0);
	close_all(infos);
	execve(infos->cmd2[0], infos->cmd2, env);
}

int	main(int ac, char **av, char **env)
{
	t_infos	infos;
	int		pid1;
	int		pid2;

	if (ac != 5)
		return (ft_putstr_fd("Syntaxe Error\n", 2), 0);
	if (pipe(infos.fd) < 0)
		return (ft_putstr_fd("Can't pipe\n", 2), 0);
	infos.infile = open(av[1], O_RDONLY);
	infos.outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (infos.infile < 0 || infos.outfile < 0)
		return (ft_putstr_fd("Cant Open The assigned files\n", 2), 0);
	fill_infos(&infos, av, env);
	pid1 = fork();
	pid2 = fork();
	if (pid1 < 0 || pid2 < 0)
		return (ft_putstr_fd("Can't Create Child process\n", 2), 0);
	if (!pid1)
		cmd1(&infos, env);
	if (!pid2)
		cmd2(&infos, env);
	close_all(&infos);
	while (wait(NULL) > 0)
		;
}
