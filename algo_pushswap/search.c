/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:07 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/02 15:05:43 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_search	*malloc_search(t_stack *a)
{
	t_search	*s;

	s = (t_search *)malloc(sizeof(t_search));
	s->n = 0;
	s->ops = (int *)malloc(sizeof(int) * 1000000);
	init_stack(&s->a, a->top + 1);
	init_stack(&s->b, a->top + 1);
	copy_stack(a, &s->a);
	return (s);
}

void		copy_search(t_search *src, t_search *dst)
{
	int			i;

	i = 0;
	dst->n = src->n;
	while (i < dst->n)
	{
		dst->ops[i] = src->ops[i];
		i++;
	}
}

void		search_do_op(t_search *search, int op)
{
	search->ops[search->n] = op;
	search->n++;
	do_cmd(&search->a, &search->b, op);
}

void		print_smallest_ops(t_search **ss)
{
	int			i;
	t_search	*min;
	char		**cmds;

	min = ss[0];
	i = 0;
	while (ss[++i])
		if (ss[i]->n < min->n && ss[i]->n != -1)
			min = ss[i];
	if (!(cmds = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ')))
		exit_ps();
	i = 0;
	while (i < min->n)
	{
		write(1, cmds[min->ops[i] - 1], ft_strlen(cmds[min->ops[i] - 1]));
		write(1, "\n", 1);
		i++;
	}
	ft_strstrfree(cmds);
}

void		free_searches(t_search **searches)
{
	int			i;

	i = 0;
	while (searches[i])
		free_search(searches[i++]);
	free(searches);
}
