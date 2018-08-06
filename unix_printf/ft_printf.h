/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct	s_printf
{
	int		leftalign; // -    left align the output, default is rightalign
	int		prependplus; // +   prepend plus if number is positive
	int		space; // prepend ' ' for positive number, overrided by prependplus
	int		zero; // 0   prepend zero for numeric types instead of spaces for numeric types
	int		hash; // #  0, 0x and 0X for ono-zero octal and hex values
	int		minwidth; // (int)    minimum number of characters to output
	int		precision; // (int)   limit number of output characters for string
	int		length; // size of int, type basically
	char	type;
}				t_printf;

#endif