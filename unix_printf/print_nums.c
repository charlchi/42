/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*format_numbers(char *str, t_printf *info, va_list va)
{
	// probably need to split between signed and unsigned
	long	n;
	int			b;
	char		out[40];
	char		base[50] = "0123456789abcdef0123456789ABCDEF";
	int			sign;
	int			i;

	n = (long) va_arg(va, int);
	if ((sign = n) < 0 && !(info->type == 'x' || info->type == 'X'
		|| info->type == 'o' || info->type == 'O'))
		n *= -1;
	b = 10;
	if (info->type == 'x' || info->type == 'X')
	{
		n = (unsigned int)n;
		b = 16;
		if (info->hash && info->type == 'x')
			write(1, "0x", 2);
		if (info->hash && info->type == 'X')
			write(1, "0X", 2);
	}
	if (info->type == 'o' || info->type == 'O')
	{
		n = (unsigned int)n;
		b = 8;
		if (info->hash)
			write(1, "0", 1);
	}
	i = 0;
	out[i++] = base[(n % b) + 16 * (info->type == 'X')];
	n /= b;
	while (n > 0)
	{
		out[i++] = base[(n % b) + 16 * (info->type == 'X')];
		n /= b;
	}
	// add zero/space here that conform to precision
	if (!(info->type == 'x' || info->type == 'X'
		|| info->type == 'o' || info->type == 'O'))
	{
		if (sign < 0)
			out[i++] = '-';
		else if (sign >= 0 && info->prependplus)
			out[i++] = '+';
	}
	// add some kind of padding here, mindwidth
	while (i-- > 0)
		write(1, &out[i], 1);
	return (str + 1);
}
