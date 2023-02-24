/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:08:05 by astalha           #+#    #+#             */
/*   Updated: 2023/02/18 14:35:13 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_putstr(char *str, int *len)
{
	int	i;
	int	n;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
		i++;
	n = i;
	i = 0;
	while (i < n)
	{
		put_char(str[i], len);
		i++;
	}
}
