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
# include <inttypes.h>
# include <wchar.h>
# include "libft/libft.h"

# define LEN_H 1
# define LEN_HH 2
# define LEN_L 3
# define LEN_LL 4
# define LEN_J 5
# define LEN_Z 6

typedef struct	s_printf
{
	int		leftalign;
	int		prependplus;
	int		space;
	int		zero;
	int		hash;
	int		minwidth;
	int		prec;
	int		length;
	char	type;
	int		cc;
}				t_printf;

void		pf_cc(t_printf *info, int c);
char		*format_numbers(char *str, t_printf *info, va_list va);

char		*format_sScC(char *str, t_printf *info, va_list va);
int			*get_arg_wstring(t_printf *info, va_list va);
int			*get_arg_string(t_printf *info, va_list va);
void		print_buffer(t_printf *info, int *buf);

char		*ft_format(char *str, t_printf *info, va_list va);
int			ft_printf(const char *format, ...);
char		get_type(char *str);
char		*get_flags(char *str, t_printf *info);
char		*get_minwidth(char *str, t_printf *info);
char		*get_precision(char *str, t_printf *info);
char		*get_length(char *str, t_printf *info);

#endif

/*
	strategy for alignment is to add all flags, precision etc..
	then pad either left or right if necessary

	int		leftalign; // -    left align the output, default is rightalign
	int		prependplus; // +   prepend plus if number is positive
	int		space; // prepend ' ' for positive number, overrided by prependplus
	int		zero; // 0   prepend zero instead of spaces for numeric types
	int		hash; // #  0, 0x and 0X for octal and hex values
	int		minwidth; // (int)    minimum number of characters to output
	int		precision; // (int)  . limit number of output characters from string
	int		length; // size of int, type basically
	s		string
	S		wide char string
	c		char
	C		widechar
	numeric types
	p		pointer
	d		int
	D		long int "ld"
	u		
	U
	i		int
	o		octal
	O		octal with caps?? "lo	"
	x		hex
	X		hex with capital
	• You must manage %%
	• You must manage the flags #0-+ and space
	• You must manage the minimum field-width
	• You must manage the precision
	• You must manage the flags 
    Modifier          d, i           o, u, x, X            n
	hh                signed char    unsigned char         signed char *
    h                 short          unsigned short        short *      
    l (ell)           long           unsigned long         long *       
    ll (ell ell)      long long      unsigned long long    long long *  
    j                 intmax_t       uintmax_t             intmax_t *   
    z                 (see note)     size_t                (see note)  
                                                                        
    The z modifier, when applied to a d or i conversion, indicates that the    
    argument is of a signed type equivalent in size to a size_t.  Similarly,   
    when applied to an n conversion, it indicates that the argument is a       
    pointer to a signed type equivalent in size to a size_t. 
*/