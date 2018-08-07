/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:04 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/02 14:53:19 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_search	*min_algo(t_stack *ap)
{
	int			max;
	int			max_i;
	t_search	*s;
	t_stack		*a;
	t_stack		*b;

	s = malloc_search(ap);
	a = &s->a;
	b = &s->b;
	while (a->top >= 0)
		search_do_op(s, PS_PB);
	while (b->top >= 0)
	{
		max = get_max_stack(b, &max_i);
		if (max_i >= b->top - max_i)
			while (st_peek(b) != max)
				search_do_op(s, PS_RB);
		else
			while (st_peek(b) != max)
				search_do_op(s, PS_RRB);
		search_do_op(s, PS_PA);
	}
	return (s);
}

int			get_min_stack(t_stack *stack, int *ip)
{
	int			i;
	int			min;
	int			min_i;

	min = stack->table[0];
	min_i = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->table[i] < min)
		{
			min = stack->table[i];
			min_i = i;
		}
		i++;
	}
	*ip = min_i;
	return (min);
}

int			get_max_stack(t_stack *stack, int *ip)
{
	int			i;
	int			max;
	int			max_i;

	max = stack->table[0];
	max_i = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->table[i] > max)
		{
			max = stack->table[i];
			max_i = i;
		}
		i++;
	}
	*ip = max_i;
	return (max);
}
