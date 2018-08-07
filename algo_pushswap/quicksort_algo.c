/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:49 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/02 14:53:11 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_search	*quicksort_algo(t_stack *aparam)
{
	t_search	*s;
	t_partition	ap;
	t_partition	bp;

	s = malloc_search(aparam);
	ap.n = -1;
	bp.n = -1;
	ap.stack = (int *)malloc(sizeof(int) * s->a.top);
	bp.stack = (int *)malloc(sizeof(int) * s->a.top);
	while (s->a.top >= 1)
		partition_to_b(&bp, s);
	while (bp.n >= 0)
	{
		partition_back_a(&ap, &bp, s);
		while (ap.n != -1)
			partition_back_b(&ap, &bp, s);
	}
	free(ap.stack);
	free(bp.stack);
	return (s);
}

void		partition_to_b(t_partition *bp, t_search *s)
{
	t_stack		*a;
	int			mid;

	a = &s->a;
	mid = get_mid(a, a->top);
	bp->stack[++bp->n] = 0;
	while (has_smallereq(mid, a))
	{
		if (a->table[a->top] <= mid)
		{
			search_do_op(s, PS_PB);
			bp->stack[bp->n]++;
		}
		else
			search_do_op(s, PS_RA);
	}
}

void		partition_back_a(t_partition *ap, t_partition *bp, t_search *s)
{
	t_stack		*b;

	b = &s->b;
	if (bp->stack[bp->n] < 3)
	{
		if (b->top > 0 && b->table[b->top] < b->table[b->top - 1])
			search_do_op(s, PS_SB);
		(b->top >= 0) ? search_do_op(s, PS_PA) : 0;
		(b->top >= 0 && bp->stack[bp->n] > 1) ? search_do_op(s, PS_PA) : 0;
		bp->n--;
	}
	else
	{
		partition(0, ap, bp, s);
	}
}

void		partition_back_b(t_partition *ap, t_partition *bp, t_search *s)
{
	if (ap->stack[ap->n] < 3)
	{
		if (s->a.top > 0 && s->a.table[s->a.top] > s->a.table[s->a.top - 1])
			search_do_op(s, PS_SA);
		ap->n--;
	}
	else
	{
		partition(1, ap, bp, s);
	}
}

void		partition(int a, t_partition *ap, t_partition *bp, t_search *s)
{
	int			g;
	int			mid;

	g = 0;
	mid = get_mid(a ? &s->a : &s->b, a ? ap->stack[ap->n] : bp->stack[bp->n]);
	if (a)
		bp->stack[++bp->n] = 0;
	else
		ap->stack[++ap->n] = 0;
	while ((a ? has_smallereq(mid, &s->a) : has_larger(mid, &s->b)))
	{
		if (a ? (s->a.table[s->a.top] <= mid) : (s->b.table[s->b.top] > mid))
		{
			search_do_op(s, a ? PS_PB : PS_PA);
			ap->stack[ap->n] += a ? -1 : 1;
			bp->stack[bp->n] += a ? 1 : -1;
		}
		else
		{
			search_do_op(s, a ? PS_RA : PS_RB);
			g++;
		}
	}
	while (g-- > 0)
		(a) ? search_do_op(s, PS_RRA) : search_do_op(s, PS_RRB);
}
