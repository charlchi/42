/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:04 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:10:06 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_search	*new_algo(t_stack *aparam)
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
	t_stack *a;

	a = &s->a;
	int mid = find_middle(a, a->top);
	int i = 0;
	while (has_smallereq(mid, a))
	{
		if (a->table[a->top] <= mid)
		{
			search_do_op(s, PS_PB);
			i++;
		}
		else
			search_do_op(s, PS_RA);
	}
	bp->stack[++bp->n] = i;
}

void		partition_back_a(t_partition *ap, t_partition *bp, t_search *s)
{
	t_stack *a;
	t_stack *b;

	a = &s->a;
	b = &s->b;
	if (bp->stack[bp->n] < 3)
	{
		if (b->top > 0 && b->table[b->top] < b->table[b->top - 1])
			search_do_op(s, PS_SB);
		if (b->top >= 0)
			search_do_op(s, PS_PA);
		if (b->top >= 0 && bp->stack[bp->n] > 1)
			search_do_op(s, PS_PA);
		bp->n--;
	} else {
		int mid = find_middle(b, bp->stack[bp->n]);
		int i = 0;
		int g = 0;
		while (has_larger(mid, b))
		{
			if (b->table[b->top] > mid)
			{
				bp->stack[bp->n]--;
				search_do_op(s, PS_PA);
				if (a->top > 0 && a->table[a->top] > a->table[a->top - 1])
					search_do_op(s, PS_SA);
				i++;
			} else {
				search_do_op(s, PS_RB);
				g++;
			}
		}
		while (g-- > 0)
			search_do_op(s, PS_RRB);
		ap->stack[++ap->n] = i;	
	}
}

void		partition_back_b(t_partition *ap, t_partition *bp, t_search *s)
{
	t_stack *a;

	a = &s->a;
	if (ap->stack[ap->n] < 3)
	{
		if (a->top > 0 && a->table[a->top] > a->table[a->top - 1])
			search_do_op(s, PS_SA);
		ap->n--;
	} else {
		int mid = find_middle(a, ap->stack[ap->n]);
		int i = 0;
		int g = 0;
		while (has_smallereq(mid, a))
		{
			if (a->table[a->top] <= mid)
			{
				ap->stack[ap->n]--;
				search_do_op(s, PS_PB);
				i++;
			} else {
				search_do_op(s, PS_RA);
				g++;
			}
		}
		bp->stack[++bp->n] = i;
		while (g-- > 0)
			search_do_op(s, PS_RRA);
	}
}

// step 1, push pivot + larger to B, while rotating A
//if partition on b is larger than 2, partition it to a, putting
// if a ever has any completed partitions, push them to b
// if the partition on a is size 2 just check swap
// if afterwards, check whether b or aneeds rotating back
// if a gets a large partition,

int has_larger(int mid, t_stack *a)
{
	int i;

	i = 0;
	while (i <= a->top)
		if (a->table[i++] > mid)
			return (1);
	return (0);
}

int has_smallereq(int mid, t_stack *a)
{
	int i;

	i = 0;
	while (i <= a->top)
		if (a->table[i++] <= mid)
			return (1);
	return (0);
}

int			find_middle(t_stack *a, int n)
{
	int i;
	int 	*table;

	table = (int *)malloc(sizeof(int) * (n + 1));
	i = 0;
	while (i <= n)
	{
		table[i] = a->table[a->top - i];
		i++;
	}
	bubble_sort(table, n + 1);
	i = (table[(n + 1) / 2]);
	free(table);
	return (i);
}

void		bubble_sort(int *tab, int size)
{
	int i;
	int j;
	int t;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t; 
			}
			j++;
		}
		i++;
	}
}