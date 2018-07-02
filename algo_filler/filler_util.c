/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:21:43 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 09:57:42 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_filler(char *l, t_filler *f)
{
	int		i;

	i = 0;
	while (i < f->h)
		free(f->m[i++]);
	free(f->m);
	free(l);
}

double	sqrtaprox(double yd, double xd)
{
	int		i;
	double	root;
	double	square;

	square = (yd * yd) + (xd * xd);
	root = square / 3;
	if (square <= 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		root = (root + square / root) / 2;
		i++;
	}
	return (root);
}

void	scan_ints(char **l, int *h, int *w)
{
	char **str;

	str = ft_strsplit(&(*l)[0], ' ');
	*h = ft_atoi(str[1]);
	*w = ft_atoi(str[2]);
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
}
