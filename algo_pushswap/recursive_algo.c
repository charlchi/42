/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:22:44 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 11:23:15 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int gsorted = 0;
t_search *gsolsearch; 

t_search	*recursive_algo(t_stack *ap)
{
	int			depth;
	int			maxdepth;
	t_search	*s;

	s = malloc_search(ap);
	gsolsearch = malloc_search(ap);
	depth = 0;
	maxdepth = 5;
	while (depth <= maxdepth && gsorted == 0)
	{
		printf("_____________depth_______________ %d\n", depth);
		find_permutation(s, 0, depth);
		depth++;
	}
	if (gsorted > 0)
	{
		free_search(s);
		return (gsolsearch);
		//printf("found solution len %d %d\n", s->n, gsorted);
	}
	else 
		s->n = -1;
	free_search(gsolsearch);
	return (s);
}

// TODO What about command list permutations?
// or permutations of rules that generate commands lists?
// look into this

// test all permutations of length len
void		find_permutation(t_search *s, int depth, int maxdepth)
{
	int			i;
	
	if (depth < maxdepth && gsorted == 0)
	{
		i = 1;
		s->n = depth + 1;
		while (i <= PS_RRR)
		{
			s->ops[depth] = i;
			if (depth - 1 < maxdepth)
				find_permutation(s, depth + 1, maxdepth);
			if (depth == maxdepth - 1 && test_permutation(s))
			{
				printf("found sorted len %d\n", s->n);
				gsorted++;
				copy_search(s, gsolsearch);
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
	test = malloc_search(&s->a); // really just copying the stacks here
	while (i < s->n)
		search_do_op(test, s->ops[i++]);
	sorted = is_sorted(test->a.table, test->a.top) && (test->b.top == -1);
	if (sorted)
	{/*
		i = 0;
		while (i < s->n)
			printf("op[%d] ", test->ops[i++]);
		printf("\n");
		i = 0;
		while (i <= s->a.top)
			printf("%d ", test->a.table[i++]);
		printf("\n");*/
		free_search(test);
		return (1);
	}
	free_search(test);
	return (0);
}