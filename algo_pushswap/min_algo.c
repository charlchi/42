/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:04 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:10:06 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

<<<<<<< HEAD
t_search	*min_algo(t_stack *ap)
=======
t_search	*min_algo(t_stack *ap, t_stack *bp)
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
{
	int			min;
	t_search	*s;
	t_stack		*a;
	t_stack		*b;

<<<<<<< HEAD
	s = malloc_search(ap);
=======
	s = malloc_search(ap, bp);
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
	a = &s->a;
	b = &s->b;
	while (a->top >= 0)
	{
		min = get_min_stack(a);
		while (st_peek(a) != min)
			search_do_op(s, PS_RA);
		search_do_op(s, PS_PB);
	}
	while (b->top >= 0)
		search_do_op(s, PS_PA);
	return (s);
}

int			get_min_stack(t_stack *stack)
{
	int			i;
	int			min;

	min = stack->table[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->table[i] < min)
			min = stack->table[i];
		i++;
	}
	return (min);
}
