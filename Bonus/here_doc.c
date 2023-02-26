/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:22:49 by astalha           #+#    #+#             */
/*   Updated: 2023/02/26 16:02:00 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_heredoc(int tmp, t_infos *infos)
{
	int	pid1;
	int	pid2;

	close(tmp);
	tmp = open("tmp", O_RDONLY);
	if (pipe(infos->fd) < 0)
		return ;
	pid1 = fork();
	if (!pid1)
		cmd(infos, tmp, infos->fd[1], 0);
	pid2 = fork();
	if (!pid2)
		cmd(infos, infos->fd[0], infos->outfile, 1);
	close(tmp);
	close(infos->fd[0]);
	close(infos->fd[1]);
}

void	read_exec(int tmp, char	**av, t_infos *infos)
{
	char	*read;

	read = ft_strdup("");
	while (1)
	{
		free(read);
		write(1, "pipe heredoc> ", 15);
		read = get_next_line(0);
		if (!read)
			break ;
		if (!ft_strcmp(read, join(ft_strdup(av[2]), "\n")))
		{
			free(read);
			break ;
		}
		write(tmp, read, ft_strlen(read));
	}
	exec_heredoc(tmp, infos);
}

void	fill(t_infos *infos, char **av)
{
	int	i;

	i = 0;
	infos->cmds = malloc((3) * sizeof(char **));
	if (!infos->cmds)
		return ;
	while (i < 2)
	{
		infos->paths = get_path(infos->env);
		infos->cmds[i] = ft_split(av[i + 3], ' ');
		infos->cmds[i][0] = get_cmd(infos->cmds[i][0], infos->paths);
		i++;
	}
	infos->cmds[i] = NULL;
}

void	fill_infos_heredoc(t_infos *infos, char **av, int ac)
{
	fill(infos, av);
	infos->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	infos->tmp = open("tmp", O_WRONLY | O_CREAT, 0777);
	if (infos->tmp < 0 || infos->outfile < 0)
		ft_putstr_fd("Cant Open The assigned files\n", 2);
	if (!errchecker_heredoc(infos))
	{
		free_all(infos);
		unlink("tmp");
		exit(1);
	}
	read_exec(infos->tmp, av, infos);
	free_all(infos);
}
