/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:48:15 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:52 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	freeindex(char	**path, int i)
{
	while (path[i])
		free(path[i++]);
	free(path);
}

int	errchecker_heredoc(t_infos *infos)
{
	int	i;

	i = 0;
	if (!infos->paths)
		return (ft_putstr_fd("bash : no path in env\n", 2), 0);
	while (i < 2)
	{
		if (!infos->cmds[i])
			return (ft_putstr_fd("Syntaxe Error\n", 2), 0);
		if (!infos->cmds[i][0])
			return (ft_putstr_fd("bash : command not found\n", 2), 0);
		i++;
	}
	return (1);
}
