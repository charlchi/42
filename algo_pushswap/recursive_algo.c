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

t_search	*recursive_algo(t_stack *ap, t_stack *bp)
{
	int			i;
	t_search	*s;

	s = malloc_search(ap, bp);

	i = 0;
	while (i < 6 && gsorted == 0)
	{
		find_permutation(s, 0, i);
		i++;
	}
	
	if (gsorted == 1)
		printf("found one\n");
	else 
		s->n = -1;
	return (s);
}

// test all permutations of length len
void		find_permutation(t_search *s, int depth, int maxdepth)
{
	int			i;

	s->n = depth;
	if (depth < maxdepth)
	{
		//printf("%d\n", depth);
		i = 1;
		while (i <= PS_RRR)
		{
			s->ops[depth] = i;
			find_permutation(s, depth + 1, maxdepth);
			if (test_permutation(s)){
				gsorted = 1;
				printf("found one of length")
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
	test = malloc_search(&s->a, &s->b); // really just copying the stacks here
	while (i < s->n)
	{
		printf("%d\t", s->ops[i]);
		search_do_op(test, s->ops[i++]);
	}
	printf("\n");
	//print_stack(&test->a);
	sorted = (is_sorted(test->a.table, test->a.top + 1) && (test->b.top == -1));
	free_search(test);
	if (sorted)
		return (1);
	return (0);
}