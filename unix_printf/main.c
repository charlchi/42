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
// int		precision; // (int)  . limit number of output characters for string
// int		length; // size of int, type basically
// s		string
// S		capital string
// p		pointer
// c		char
// C		widechar
// numeric types
// d		int
// D		int???
// i		int
// o		octal
// O		octal with caps??
// x		hex
// X		hex with capital
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
// hh 0 h 1 ll 2 l 3 j 4 z 5

char		get_type(char *str)
{
	while (!ft_strchr("sSpcCdDioOxX", *str))
		str++;
	return *str;
}

char		*get_flag(char *str, t_printf *info)
{
	if (*str == '-' && (info->leftalign = 1))
		return (str + 1);
	if (*str == '+' && (info->prependplus = 1))
		return (str + 1);
	if (*str == ' ' && (info->space = 1))
		return (str + 1);
	if (*str == '#' && (info->hash = 1))
		return (str + 1);
	if (*str == '0' && (info->zero = 1))
		return (str + 1);
	return (str);
}

char		*get_flags(char *str, t_printf *info)
{
	info->leftalign = 0;
	info->prependplus = 0;
	info->space = 0;
	info->hash = 0;
	info->zero = 0;
	while (ft_strchr("-+ 0#", *str))
	{
		if (*str == '0' && info->zero == 1)
			break;
		str = get_flag(str, info);
	}
	return (str);
}

char		*get_minwidth(char *str, t_printf *info)
{

	if (ft_isdigit(*str))
	{
		info->minwidth = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		return (str);
	}
	return (str);
} 

char		*get_precision(char *str, t_printf *info)
{
	if (*str == '.')
	{
		str++;
		if (ft_isdigit(*str))
			info->minwidth = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		return (str);
	}
	return (str);
}

char		*get_length(char *str, t_printf *info)
{
	info->length = 0;
	if (str[0] == 'h' && str[1] == 'h' && (info->length = 1))
		return (str + 2);
	if (str[0] == 'h' && (info->length = 2))
		return (str + 1);
	if (str[0] == 'l' && str[1] == 'l' && (info->length = 3))
		return (str + 2);
	if (str[0] == 'h' && (info->length = 4))
		return (str + 1);
	if (str[0] == 'j' && (info->length = 5))
		return (str + 1);
	if (str[0] == 'z' && (info->length = 6))
		return (str + 1);
	return (str);
}

char		*ft_format(char *str, va_list va)
{
	t_printf	info;

	info->type = get_type(str);
	str = get_flags(str, &info);
	str = get_minwidth(str, &info);
	str = get_precision(str, &info);
	if (ft_strchr("dDioOxX", *str))
		str = get_length(str, &info);
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
	ft_printf(" %d HI! %d HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	printf(" %d HI! %d HI! %d HI! %d HI!\n", 50, 51, 52, 53);
	ft_printf("MINE>\t[%-+d]\n", 650);
	printf("ORIG>\t[%-+d]\n", 650);
	return (0);
}

