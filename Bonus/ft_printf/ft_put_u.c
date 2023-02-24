/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:08:10 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:11 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_put_u(unsigned int nb, int *len)
{
	if (nb < 10)
		put_char (nb + 48, len);
	else
	{
		ft_putnbr (nb / 10, len);
		ft_putnbr (nb % 10, len);
	}
}
