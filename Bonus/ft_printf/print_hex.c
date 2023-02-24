/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:38:06 by astalha           #+#    #+#             */
/*   Updated: 2023/02/24 20:43:31 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	print_hex(unsigned int n, int *len, char uplow)
{
	if (n < 10)
		put_char (n + '0', len);
	else if (n < 16 && uplow == 'l')
		put_char (n % 10 + 'a', len);
	else if (n < 16 && uplow == 'u')
		put_char (n % 10 + 'A', len);
	else
	{
		print_hex (n / 16, len, uplow);
		print_hex (n % 16, len, uplow);
	}
}
