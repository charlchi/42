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
<<<<<<< HEAD
t_search *gsolsearch; 
=======
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda

t_search	*recursive_algo(t_stack *ap)
{
	int			depth;
	int			maxdepth;
	t_search	*s;

	s = malloc_search(ap);
<<<<<<< HEAD
	gsolsearch = malloc_search(ap);
	depth = 1;
	maxdepth = 8;
	while (depth <= maxdepth && gsorted == 0)
	{
		//printf("_____________depth %d_______________\n", depth);
=======

	depth = 1;
	maxdepth = 11;
	while (depth <= maxdepth && gsorted == 0)
	{
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
		find_permutation(s, 0, depth);
		depth++;
	}
	
	if (gsorted > 0)
	{
<<<<<<< HEAD
		free_search(s);
		return (gsolsearch);
=======
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
		//printf("found solution len %d %d\n", s->n, gsorted);
	}
	else 
		s->n = -1;
<<<<<<< HEAD
	free_search(gsolsearch);
=======
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
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
<<<<<<< HEAD
		while (i <= PS_RRR)
		//while (i <= PS_RA)
		{
=======
		//while (i <= PS_RRR)
		while (i <= PS_PB)
		{
			
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
			if (depth - 1 < maxdepth && gsorted == 0)
			{
				s->ops[depth] = i;
				find_permutation(s, depth + 1, maxdepth);
			}
			if (gsorted == 0 && test_permutation(s))
			{
<<<<<<< HEAD
				//printf("found sorted\n");
				gsorted++;
				copy_search(s, gsolsearch);
=======
				gsorted++;
>>>>>>> f6684ba070e64290b4eba2333a72ccfe3700dfda
				break;
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
		printf("\n");
		free_search(test);*/
		return (1);
	}
	free_search(test);
	return (0);
}