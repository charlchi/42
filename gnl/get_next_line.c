/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:51:45 by cmoller           #+#    #+#             */
/*   Updated: 2018/05/31 10:19:35 by cmoller          ###   ########.fr       */
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

int		get_next_line(const int fd, char **l)
{
	static char		buff[1000][BUFF_SIZE + 1];
	int				i;
	int				j;
	int				r;



	if ((!l || f < 0))
		return (-1);

	if (!(*l = (char *)malloc(52000))) // TODO: add gnl_realloc();
		return (-1);

	// if buff isn't empty, get its strlen as r
	// you still have characters to process from previous line
	r = gnl_strlen(&buff[f][0]);
	if (r == 0) // if there isn't any characters in buff, read()
		r = read(f, &buff[f][0], BUFF_SIZE);
	b[f][r] = 0; // add '\0' to buffer. buff is [BUFFSIZ + 1] for this
	i = 0;
	while (r > 0)
	{
		j = 0;
		while (j < r) // copy over characters from buffer one by one
		{
			// TODO	if ( i + r > current line malloc size)
			// 			gnl_realloc())
			(*l)[i++] = b[f][j++];
			if ((*l)[i - 1] == '\n') // if newline
				// push back characters in buffer and return;
			{
				gnl_strcpy(&b[f][j], &b[f][0]);
				(*l)[i - 1] = 0;
				return (1);
			}
		}
		r = read(f, &b[f][0], BUFF_SIZE);
		b[f][r] = 0;
	}
	if (i > 0) // r == 0 : EOF encountered, but line is not null
		return (1);
	return (r);
}
