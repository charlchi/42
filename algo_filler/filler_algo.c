/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:21:43 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 10:00:28 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			rank_overlap(t_filler *f, t_opieces *op, t_piece *p)
{
	int		i;
	int		j;
	int		overlap;
	int		ret;

	ret = 0;
	i = 0;
	while (i < op->n)
	{
		j = -1;
		overlap = 0;
		while (++j < p->n)
			if (f->m[op->y[i] + p->y[j]][op->x[i] + p->x[j]] == '*')
				overlap++;
		if (overlap >= ret)
		{
			ret = overlap;
			op->y[op->n] = op->y[i];
			op->x[op->n] = op->x[i];
		}
		i++;
	}
	return (ret > 0);
}

void		rank_dist(t_filler *f, t_opieces *op, t_opieces *eop, t_piece *p)
{
	int		i;
	int		j;
	int		ret;
	double	smallest;

	smallest = 100000.0;
	i = -1;
	while (++i < op->n)
	{
		j = -1;
		while (++j < eop->n)
		{
			ret = sqrtaprox(
				((double)op->y[i] + ((double)p->w / 2.0)) - (double)eop->y[j],
				((double)op->x[i] + ((double)p->h / 2.0)) - (double)eop->x[j]);
			if (ret <= smallest)
			{
				smallest = ret;
				op->y[op->n] = op->y[i];
				op->x[op->n] = op->x[i];
			}
		}
	}
}
