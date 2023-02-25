/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:01:33 by astalha           #+#    #+#             */
/*   Updated: 2023/02/25 13:03:21 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	npaths(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

char	**get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4))
		i++;
	if (i == npaths(env))
		return (NULL);
	return (ft_split(env[i] + 5, ':'));
}

char	*get_the_way(char *cmd, char **paths)
{
	int		i;
	char	*cmdcheck;

	i = 0;
	while (paths[i])
	{
		cmdcheck = join(paths[i], cmd);
		if (!access(cmdcheck, F_OK))
			return (free(cmd), cmdcheck);
		free(cmdcheck);
		i++;
	}
	return (free(cmd), NULL);
}

int	ifslash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*get_cmd(char *cmd, char **paths)
{
	int		i;
	int		j;
	char	*fcmd;

	i = 0;
	j = 0;
	if (!cmd)
		return (NULL);
	if (!paths)
		return (free(cmd), NULL);
	if (!ifslash(cmd))
	{
		fcmd = join(ft_strdup("/"), cmd);
		return (free(cmd), get_the_way(fcmd, paths));
	}
	if (ifslash(cmd))
	{
		while (cmd[i])
			i++;
		while (cmd[i] != '/')
			i--;
		fcmd = ft_substr(cmd, i, ft_strlen(cmd));
		return (free(cmd), get_the_way(fcmd, paths));
	}
	return (NULL);
}
