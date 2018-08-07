/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:22:44 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/02 14:54:57 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_search	*recursive_algo(t_stack *ap)
{
	int			depth;
	int			maxdepth;
	t_search	*s;
	t_search	*gsol;

	s = malloc_search(ap);
	gsol = malloc_search(ap);
	depth = 0;
	maxdepth = 7;
	while (depth <= maxdepth && gsol->n == 0)
	{
		find_permutation(gsol, s, 0, depth);
		depth++;
	}
	if (gsol->n > 0)
	{
		free_search(s);
		return (gsol);
	}
	else
		s->n = -1;
	free_search(gsol);
	return (s);
}

void		find_permutation(t_search *gsol, t_search *s, int depth, int max)
{
	int			i;

	if (depth < max && gsol->n == 0)
	{
		i = 1;
		s->n = depth + 1;
		while (i <= PS_RRR)
		{
			s->ops[depth] = i;
			if (depth - 1 < max)
				find_permutation(gsol, s, depth + 1, max);
			if (depth == max - 1 && test_permutation(s))
			{
				gsol->n++;
				copy_search(s, gsol);
				return ;
			}
			i++;
		}
	}
}

int			test_permutation(t_search *s)
{
	int			i;
	int			sorted;
	t_search	*test;

	i = 0;
	test = malloc_search(&s->a);
	while (i < s->n)
		search_do_op(test, s->ops[i++]);
	sorted = is_sorted(test->a.table, test->a.top) && (test->b.top == -1);
	if (sorted)
	{
		free_search(test);
		return (1);
	}
	free_search(test);
	return (0);
}
