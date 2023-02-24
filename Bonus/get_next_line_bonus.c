/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:52:11 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:46 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cpy(char *s1, char *s2, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		while (s2[i] && s2[i] != '\n')
		{
			s1[i] = s2[i];
			i++;
		}
		if (s2[i] == '\n')
			s1[i++] = '\n';
		s1[i] = 0;
	}
	else
	{
		while (s2[j])
			s1[i++] = s2[j++];
		s1[i] = 0;
	}
}

char	*justrest(char *hold)
{
	char	*newhold;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (hold[i] == '\n')
		i++;
	if (i == ft_strlen(hold))
		return (free(hold), NULL);
	newhold = malloc(ft_strlen(hold) - i + 1);
	if (!newhold)
		return (NULL);
	cpy(newhold, hold, i);
	return (free(hold), hold = NULL, newhold);
}

char	*join(char *s1, char *s2)
{
	char	*ptr;

	if (!s2)
		return (s1);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (free(s1), free(s2), NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (ptr);
}

char	*get_the_line(char *hold)
{
	char	*line;
	int		i;

	i = 0;
	if (!hold[0])
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	cpy(line, hold, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*line;
	char		*ret;
	int			re;

	re = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!hold)
		hold = ft_strdup("");
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (re && check(hold))
	{
		re = read(fd, line, BUFFER_SIZE);
		if (re < 0)
			return (free(hold), hold = NULL, free(line), NULL);
		line[re] = 0;
		hold = join(hold, line);
	}
	free(line);
	ret = get_the_line(hold);
	hold = justrest(hold);
	return (ret);
}
