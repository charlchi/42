/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_normalchars(t_printf *info, va_list va)
{
	int			i;
	int			p;
	char		*buf;

	i = 0;
	p = 0;
	if (info->type == 's')
		buf = va_arg(va, char *);
	else
	{
		buf = (char *)malloc(sizeof(char) * 2);
		buf[0] = va_arg(va, int);
		buf[1] = '\0';
	}
	;
	int test = info->minwidth - ft_strlen(buf);
	if (info->minwidth - info->precision > test)
		test = info->minwidth - info->precision;
	while (!info->leftalign && i < test)
	{
		ft_putchar(' ');
		i++;
	}
	while (*buf && p < info->precision)
	{
		if (info->precision != 0 && i > info->precision)
			break;
		i++;
		p++;
		ft_putchar(*buf++);
	}
	//ft_putnbr(i);
	while (i < info->minwidth)
	{
		if (*buf && i - info->minwidth < info->precision && p < info->precision)
		{
			ft_putchar(*buf++);
			p++;
		}
		else
			ft_putchar(' ');
		i++;
	}
}

void		format_widechars(t_printf *info, va_list va)
{
	int			i;
	wchar_t		*wbuf;
	
	i = 0;
	if (info->type == 'S')
		wbuf = va_arg(va, wchar_t *);
	else
	{
		wbuf = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		wbuf[0] = va_arg(va, wchar_t);
		wbuf[1] = '\0';
	}
	while (*wbuf)
	{
		i++;
		ft_putchar(*wbuf++);
	}
}
