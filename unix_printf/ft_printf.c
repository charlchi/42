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

char		*format_characters(char *str, t_printf *info, va_list va)
{
	int			i;

	i = 0;
	if (info->type == 's' || info->type == 'c')
		format_normalchars(info, va);
	else if (info->type == 'S' || info->type == 'C')
		format_widechars(info, va);
	return (str + 1);
}

char		*ft_format(char *str, va_list va)
{
	t_printf	info;

	info.type = get_type(str);
	str = get_flags(str, &info);
	str = get_minwidth(str, &info);
	str = get_precision(str, &info);
	if (ft_strchr("pdDuUioOxX", info.type))
		str = get_length(str, &info);
	if (*str == '%')
	{
		write(1, str++, 1);
		str++;
	}
	else if (ft_strchr("sScC", info.type))
		str = format_characters(str, &info, va);
	else if (ft_strchr("pdDuUioOxX", info.type))
		str = format_numbers(str, &info, va);
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
