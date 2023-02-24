/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:26:29 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:44:05 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd(t_infos *infos, int infile, int outfile, int i)
{
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close_all(infile, outfile, infos);
	execve(infos->cmds[i][0], infos->cmds[i], infos->env);
}

void	ft_pre_fd(int *pre_fd, t_infos *infos, int *i)
{
	close(*pre_fd);
	*pre_fd = dup(infos->fd[0]);
	close(infos->fd[0]);
	close(infos->fd[1]);
	(*i)++;
}

int	execpipes(int *i, t_infos *infos, int pre_fd, int ac)
{
	int	pids;

	if (pipe(infos->fd) < 0)
		return (ft_putstr_fd("Can't pipe\n", 2), exit(1), 0);
	pids = fork();
	if (pids == -1)
		exit(1);
	else if (!pids)
	{
		if (*i == 0)
			cmd(infos, infos->infile, infos->fd[1], *i);
		else if (*i == ac - 4)
			cmd(infos, pre_fd, infos->outfile, *i);
		else
			cmd(infos, pre_fd, infos->fd[1], *i);
	}
	else
		ft_pre_fd(&pre_fd, infos, i);
	return (1);
}

int	pipes(int ac, t_infos *infos)
{
	int	i;
	int	pre_fd;

	i = 0;
	pre_fd = dup(infos->fd[0]);
	while (i < ac - 3)
		execpipes(&i, infos, pre_fd, ac);
	close(pre_fd);
	close_all(infos->infile, infos->outfile, infos);
	while (wait(NULL) > 0)
		;
	free_all(infos);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_infos	infos;

	infos.env = env;
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
	{
		fill_infos_heredoc(&infos, av, ac);
		unlink("tmp");
		exit(0);
	}
	infos.infile = open(av[1], O_RDONLY);
	infos.outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (infos.infile < 0 || infos.outfile < 0)
		return (ft_putstr_fd("Cant Open The assigned files\n", 2), 0);
	else
	{
		fill_infos(&infos, av, ac);
		pipes(ac, &infos);
	}
}
