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

intmax_t		get_argnum(t_printf *info, va_list va)
{
	if (info->length == LEN_HH)
		return ((char)va_arg(va, int));
	if (info->length == LEN_H)
		return ((short)va_arg(va, int));
	if (info->length == LEN_L)
		return (va_arg(va, long));
	if (info->length == LEN_LL)
		return (va_arg(va, long long));
	if (info->length == LEN_J)
		return (va_arg(va, intmax_t));
	if (info->length == LEN_Z)
		return (va_arg(va, ssize_t));
	return (va_arg(va, int));
}

uintmax_t		get_argunum(t_printf *info, va_list va)
{
	if (info->length == LEN_HH)
		return ((unsigned char)va_arg(va, unsigned int));
	if (info->length == LEN_H)
		return ((unsigned short)va_arg(va, unsigned int));
	if (info->length == LEN_L)
		return (va_arg(va, unsigned long));
	if (info->length == LEN_LL)
		return (va_arg(va, unsigned long long));
	if (info->length == LEN_J)
		return (va_arg(va, uintmax_t));
	if (info->length == LEN_Z)
		return (va_arg(va, size_t));
	return (va_arg(va, unsigned int));
}

char		*get_num_string(t_printf *info, intmax_t n)
{
	intmax_t	sign;
	char		base[50] = "0123456789abcdef0123456789ABCDEF";
	int			b;
	int			i;
	char		*out;

	out = malloc(sizeof(char) * 50);
	if ((sign = n) < 0)
		n *= -1;
	b = 10;
	i = 0;
	out[i++] = base[(n % b) + 16 * (info->type == 'X')];	
	while ((n /= b) > 0)
		out[i++] = base[(n % b) + 16 * (info->type == 'X')];
	out[i] = '\0';
	ft_strrev(&out);
	return (out);
}

char		*get_unum_string(t_printf *info, uintmax_t n)
{
	char		base[50] = "0123456789abcdef0123456789ABCDEF";
	int			b;
	int			i;
	char		*out;

	out = malloc(sizeof(char) * 50);
	b = 10;
	i = 0;
	if (info->type == 'x' || info->type == 'X')
		b = 16;
	if (info->type == 'o' || info->type == 'O')
		b = 8;
	out[i++] = base[(n % b) + 16 * (info->type == 'X')];	
	while ((n /= b) > 0)
		out[i++] = base[(n % b) + 16 * (info->type == 'X')];
	out[i] = '\0';
	ft_strrev(&out);
	return (out);
}

void		format_d(t_printf *info, char *numstr)
{
	(void)info;
	ft_putstr(numstr);
}
void		format_p(t_printf *info, char *numstr)
{
	(void)info;
	ft_putstr(numstr);
}
void		format_u(t_printf *info, char *numstr)
{
	(void)info;
	ft_putstr(numstr);
}
void		format_U(t_printf *info, char *numstr)
{
	(void)info;
	ft_putstr(numstr);
}
void		format_oO(t_printf *info, char *numstr)
{
	(void)info;
	ft_putstr(numstr);
}
void		format_xX(t_printf *info, char *numstr)
{
	(void)info;
	ft_putstr(numstr);
}

char		*format_numbers(char *str, t_printf *info, va_list va)
{
	// split this into signed and unsigned check out:
	// https://github.com/sploadie/ft-printf/blob/master/printf/get_conv_num.c
	intmax_t	n;
	uintmax_t	un;
	char		*out;

	if (info->type == 'd' || info->type == 'i')
	{
		n = get_argnum(info, va);
		out = get_num_string(info, n);
	}
	else
	{
		un = get_argunum(info, va);
		out = get_unum_string(info, un);
	}
	if (info->type == 'd' || info->type == 'i')
		format_d(info, out);
	else if (info->type == 'p')
		format_p(info, out);
	else if (info->type == 'u')
		format_u(info, out);
	else if (info->type == 'U')
		format_U(info, out);
	else if (info->type == 'o' || info->type == 'O')
		format_oO(info, out);
	else if (info->type == 'x' || info->type == 'X')
		format_xX(info, out);
	return (str + 1);
}






/*

	i = ft_strlen(out);
	p = info->prec - i - info->prependplus - info->space;
	if (info->type == 'x' || info->type == 'X')
		p -= 1;
	if (info->type == 'o' || info->type == 'O')
		p -= 2;
	while (p-- >= 0)
		out[i++] = info->zero ? '0' : ' ';
	if (info->hash)
	{
		if (info->type == 'x' || info->type == 'X')
			out[i++] = info->type == 'x' ? 'x' : 'X';
		out[i++] = '0';
	}
	//mprintf("[[min%d, prec%d, i%d, p%d]]\n", info->minwidth, info->prec, i, p);
	while (!info->leftalign && info->prec == -1 && i < info->minwidth - info->prependplus - info->space)
		out[i++] = info->zero ? '0' : ' ';
	if (!(info->type == 'x' || info->type == 'X'
		|| info->type == 'o' || info->type == 'O'))
	{
		if (n < 0)
			out[i++] = '-';
		else if (n >= 0 && info->prependplus)
			out[i++] = '+';
		else if (info->space)
			out[i++] = ' ';
	}
	p = ft_max(info->minwidth, info->prec + info->prependplus) - i;
	while (!info->leftalign && p-- > 0)
		pf_cc(info, info->zero ? '0' : ' ');
	while (i-- > 0)
		pf_cc(info, out[i]);
	while (info->leftalign && p-- > 0)
		pf_cc(info, ' ');
	return (str + 1);
*/








