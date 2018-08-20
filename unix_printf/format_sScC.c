/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_sScC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:47:37 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/20 12:47:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*get_arg_wstring(t_printf *info, va_list va)
{
	int		*ret;
	wchar_t	*wbuf;
	int		i;

	i = -1;
	if (info->type == 'S')
	{
		wbuf = va_arg(va, wchar_t *);
		if (wbuf == NULL)
			return NULL;
	}
	else if (info->type == 'C')
	{
		wbuf = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		wbuf[0] = va_arg(va, wchar_t);
		wbuf[1] = '\0';
	}
	ret = (int *)malloc(sizeof(int) * ft_wstrlen(wbuf));
	while (i++ <= ft_wstrlen(wbuf))
		ret[i] = wbuf[i];
	return (ret);
}

int		*get_arg_string(t_printf *info, va_list va)
{
	int		*ret;
	char	*buf;
	int		i;

	i = -1;
	if (info->type == 's')
	{
		buf = va_arg(va, char *);
		if (buf == NULL)
			return NULL;
	}
	else if (info->type == 'c')
	{
		buf = (char *)malloc(sizeof(char) * 2);
		buf[0] = va_arg(va, int);
		buf[1] = '\0';
	}
	ret = (int *)malloc(sizeof(int) * ft_strlen(buf));
	while (i++ <= ft_strlen(buf))
		ret[i] = buf[i];
	return (ret);
}

void	print_buffer(t_printf *info, int *buf)
{
	int			i;
	int			p;
	int			test;

	i = 0;
	p = 0;
	if (info->prec == -1)
		info->prec = ft_intlen(buf);
	test = ft_max(info->minwidth - ft_intlen(buf), info->minwidth - info->prec);
	while (!info->leftalign && i < test)
	{
		pf_cc(info, ' ');
		i++;
	}
	while (*buf && p < info->prec && !(info->prec != -1 && i > info->prec))
	{
		i++;
		p++;
		pf_cc(info, *buf++);
	}
	while (i < info->minwidth)
	{
		if (*buf && i - info->minwidth < info->prec && p++ < info->prec)
			pf_cc(info, *buf++);
		else
			pf_cc(info, ' ');
		i++;
	}
}

char	*format_sScC(char *str, t_printf *info, va_list va)
{
	int *buf;

	if (info->type == 'c' || info->type == 's')
		buf = get_arg_string(info, va);
	else 
		buf = get_arg_wstring(info, va);
	if (buf == NULL)
	{
		pf_cc(info, '(');
		pf_cc(info, 'n');
		pf_cc(info, 'u');
		pf_cc(info, 'l');
		pf_cc(info, 'l');
		pf_cc(info, ')');
	}
	else
		print_buffer(info, buf);
	return (str + 1);
}
