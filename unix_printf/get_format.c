/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		get_type(char *str)
{
	while (!ft_strchr("sSpuUcCdDioOxX", *str))
		str++;
	return *str;
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
		if (*str == '-' && (info->leftalign = 1))
			str++;
		if (*str == '+' && (info->prependplus = 1))
			str++;
		if (*str == ' ' && (info->space = 1))
		{
			str++;
			if (info->prependplus)
				info->space = 0;
		}
		if (*str == '#' && (info->hash = 1))
			str++;
		if (*str == '0' && (info->zero = 1))
			str++;
	}
	return (str);
}

char		*get_minwidth(char *str, t_printf *info)
{
	info->minwidth = -1;
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
	info->prec = -1;
	if (*str == '.')
	{
		info->prec = 0;
		str++;
		if (ft_isdigit(*str))
			info->prec = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		return (str);
	}
	return (str);
}

char		*get_length(char *str, t_printf *info)
{
	info->length = 0;
	if (str[0] == 'h' && str[1] == 'h' && (info->length = LEN_HH))
		return (str + 2);
	if (str[0] == 'h' && (info->length = LEN_H))
		return (str + 1);
	if (str[0] == 'l' && str[1] == 'l' && (info->length = LEN_LL))
		return (str + 2);
	if (str[0] == 'l' && (info->length = LEN_LL))
		return (str + 1);
	if (str[0] == 'j' && (info->length = LEN_J))
		return (str + 1);
	if (str[0] == 'z' && (info->length = LEN_Z))
		return (str + 1);
	return (str);
}
