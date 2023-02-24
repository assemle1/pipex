/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:06:26 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:23 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		put_char('-', len);
		ft_putnbr(n, len);
	}
	else
	{
		if (n < 10)
			put_char(n + 48, len);
		else
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
	}
}
