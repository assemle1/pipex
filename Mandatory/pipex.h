/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:01:18 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 21:09:43 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_infos
{
	char	**paths1;
	char	**paths2;
	char	**cmd1;
	char	**cmd2;
	int		infile;
	int		outfile;
	int		fd[2];
}							t_infos;

//libft
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char	*str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);
char		*join(char *s1, char *s2);
int			check(char *line);
void		ft_strlcpy(char *dst, char *src, size_t dstsize);
void		ft_putstr_fd(char *s, int fd);
//parcing
char		**get_path(char **env);
char		*get_the_way(char *cmd, char **paths);
int			ifslash(char *str);
char		*get_cmd(char *cmd, char **paths);
int			npaths(char **path);
//check_clean
void		freealloc2(char **ptr);
int			errchecker(t_infos *infos);
void		free_all(t_infos *infos);
void		close_all(t_infos *infos);
void		fill_infos(t_infos *infos, char **av, char **env);
//ft_printf
int			ft_printf(const char *format, ...);
void		put_char(char c, int *len);
void		ft_putadd(unsigned long long n, int *len);
void		print_hex(unsigned int n, int *len, char uplow);
void		ft_putnbr(int n, int *len);
void		ft_put_u(unsigned int nb, int *len);
void		ft_putstr(char *str, int *len);

#endif