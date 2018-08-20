/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_cc(t_printf *info, int c)
{
	info->cc++;
	if (c == 0)
	{
		ft_putchar('^');
		ft_putchar('@');
	}
	else
		ft_putchar(c);
}

char		*ft_format(char *str, t_printf *info, va_list va)
{
	info->type = get_type(str);
	str = get_flags(str, info);
	str = get_minwidth(str, info);
	str = get_precision(str, info);
	if (ft_strchr("pdDuUioOxX", info->type))
		str = get_length(str, info);
	if (*str == '%')
		pf_cc(info, *str++);
	else if (ft_strchr("sScC", info->type))
		str = format_sScC(str, info, va);
	else if (ft_strchr("pdDuUioOxX", info->type))
		str = format_numbers(str, info, va);
	return (str);
}

int		ft_printf(const char *format, ...)
{
	t_printf	info;
	va_list		va;
	char		*str;

	va_start(va, format);
	str = (char *)format;
	info.cc = 0;
	while (*str)
	{
		if (*str == '%')
			str = ft_format(++str, &info, va);
		else
			pf_cc(&info, *str++);
	}
	va_end(va);
	return (info.cc);
}
