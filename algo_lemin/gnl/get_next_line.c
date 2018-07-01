/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:51:45 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/07 09:14:52 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_strcpy(char *src, char *dst)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (0);
}

int		gnl_strlen(char *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int		get_next_line(const int f, char **l)
{
	static char		b[1000][BUFF_SIZE + 1];
	int				i;
	int				j;
	int				r;

	i = 0;
	if ((!l || f < 0))
		return (-1);
	if (!(*l = (char *)malloc(52000)))
		return (-1);
	if ((r = gnl_strlen(&b[f][0])) == 0)
		r = read(f, &b[f][0], BUFF_SIZE);
	b[f][r] = 0;
	while (r > 0)
	{
		j = 0;
		while (j < r && ((*l)[i++] = b[f][j++]))
			if ((*l)[i - 1] == '\n')
				return (((*l)[i - 1] = gnl_strcpy(&b[f][j], &b[f][0])) + 1);
		r = read(f, &b[f][0], BUFF_SIZE);
		b[f][r] = 0;
	}
	if (i > 0)
		return (1);
	return (r);
}
