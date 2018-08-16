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
	// split into different function starting here
	if (info->prec == -1)
		info->prec = ft_strlen(buf);
	int test = info->minwidth - ft_strlen(buf);
	if (info->minwidth - info->prec > test)
		test = info->minwidth - info->prec;
	while (!info->leftalign && i < test)
	{
		ft_putchar(' ');
		i++;
	}
	while (*buf && p < info->prec && !(info->prec != -1 && i > info->prec))
	{
		i++;
		p++;
		ft_putchar(*buf++);
	}
	while (i < info->minwidth)
	{
		if (*buf && i - info->minwidth < info->prec && p++ < info->prec)
			ft_putchar(*buf++);
		else
			ft_putchar(' ');
		i++;
	}
}


void		format_widechars(t_printf *info, va_list va)
{
	int			i;
	int			p;
	wchar_t		*buf;
	
	i = 0;
	p = 0;
	if (info->type == 'S')
		buf = va_arg(va, wchar_t *);
	else
	{
		buf = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		buf[0] = va_arg(va, wchar_t);
		buf[1] = '\0';
	}
	if (info->prec == -1)
		info->prec = ft_wstrlen(buf);
	int test = info->minwidth - ft_wstrlen(buf);
	if (info->minwidth - info->prec > test)
		test = info->minwidth - info->prec;
	while (!info->leftalign && i < test)
	{
		ft_putchar(' ');
		i++;
	}
	while (*buf && p < info->prec && !(info->prec != -1 && i > info->prec))
	{
		i++;
		p++;
		ft_putchar(*buf++);
	}
	while (i < info->minwidth)
	{
		if (*buf && i - info->minwidth < info->prec && p++ < info->prec)
			ft_putchar(*buf++);
		else
			ft_putchar(' ');
		i++;
	}
}
