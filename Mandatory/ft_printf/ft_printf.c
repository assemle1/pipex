/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:22:19 by astalha           #+#    #+#             */
/*   Updated: 2023/02/18 14:34:57 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_arg(va_list list, char c, int *len)
{
	if (c == 'c')
		put_char (va_arg (list, int), len);
	else if (c == 's')
		ft_putstr (va_arg (list, char *), len);
	else if (c == 'p')
	{
		ft_putstr ("0x", len);
		ft_putadd (va_arg (list, unsigned long long), len);
	}
	else if (c == 'x')
		print_hex (va_arg (list, int), len, 'l');
	else if (c == 'X')
		print_hex (va_arg (list, int), len, 'u');
	else if (c == 'i' || c == 'd')
		ft_putnbr (va_arg (list, int), len);
	else if (c == 'u')
		ft_put_u (va_arg (list, int), len);
	else if (c == '%')
		put_char ('%', len);
	else
		put_char(c, len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	list;

	len = 0;
	va_start (list, format);
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			break ;
		else if (*format == '%')
		{
			print_arg (list, *(format + 1), &len);
			format++;
		}
		else
			put_char (*format, &len);
		format++;
	}
	va_end (list);
	return (len);
}
