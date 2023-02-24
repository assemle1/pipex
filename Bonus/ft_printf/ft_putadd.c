/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:07:45 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:19 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_putadd(unsigned long long n, int *len)
{
	if (n < 10)
		put_char (n + '0', len);
	else if (n < 16)
		put_char (n % 10 + 'a', len);
	else
	{
		ft_putadd (n / 16, len);
		ft_putadd (n % 16, len);
	}
}
