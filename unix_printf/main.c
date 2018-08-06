/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int		leftalign; // -    left align the output, default is rightalign
// int		prependplus; // +   prepend plus if number is positive
// int		space; // prepend ' ' for positive number, overrided by prependplus
// int		zero; // 0   prepend zero for numeric types instead of spaces for numeric types
// int		hash; // #  0, 0x and 0X for ono-zero octal and hex values
// int		minwidth; // (int)    minimum number of characters to output
// int		precision; // (int)   limit number of output characters for string
// int		length; // size of int, type basically
// s		string
// S		capital string
// p		pointer
// d		int
// D		int???
// i		int
// o		octal
// O		octal with caps??
// x		hex
// X		hex with capital
// c		char
// C		widechar
// • You must manage %%
// • You must manage the flags #0-+ and space
// • You must manage the minimum field-width
// • You must manage the precision
// • You must manage the flags 
// hh, (char)d 
// h, (short)d
// l, print long
// ll, print longlong
// j, intmax_t sized?widest range possible on platform used, use sizeof
// z ptrdiff_t sized

char		*get_flags(char *str, t_printf *info)
{
	info->leftalign = *str == '-' ? 1 : 0;
	str += info->leftalign;
	info->prependplus = *str == '+' ? 1 : 0;
	str += info->prependplus;
	info->space = *str == ' ' ? 1 : 0;
	str += info->space;
	info->zero = *str == '0' ? 1 : 0;
	str += info->zero;
	info->hash = *str == '#' ? 1 : 0;
	str += info->hash;
	return (str);
}

char		*ft_format(char *str, va_list va)
{
	t_printf	info;



	str = get_flags(str, &info);
	// str = get_type(str, &info);
	// check type is "idDoOuUxXp"
	if (*str == '%')
	{
		write(1, str++, 1);
		str++;
	}
	else if (*str == 'd')
	{
		int num = va_arg(va, int);
		char *numstr = ft_itoa(num);
		ft_putstr(numstr);
		str++;
	}
	return (str);
}

int		ft_printf(const char *format, ...)
{
	va_list		va;
	int			ret;
	char		*str;

	va_start(va, format);
	str = (char *)format;
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_format(++str, va); /* This will put *str right after argument*/
			ret++;
		}
		else
			write(1, str++, 1);
	}
	va_end(va);
	return (ret);
}

int			main(void)
{
	int c = 5333;
	printf("%hhd\n", c);
	printf("%d\n", (char)c);
	ft_printf(" %d HI! %d HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	return (0);
}

