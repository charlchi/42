/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:07 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:11:21 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_search	*malloc_search(t_stack *a, t_stack *b)
{
	t_search	*ret;

	ret = (t_search *)malloc(sizeof(t_search));
	ret->n = 0;
	ret->ops = (int *)malloc(sizeof(int) * 10000);
	init_stack(&ret->a, a->top + 1);
	init_stack(&ret->b, a->top + 1);
	copy_stack(a, &ret->a);
	return (ret);
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
		if (ss[i]->n < min->n)
			min = ss[i];
	if (!(cmds = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ')))
		exit_error();
	i = -1;
	while (++i < min->n)
	{
		write(1, cmds[min->ops[i] - 1], ft_strlen(cmds[min->ops[i] - 1]));
		write(1, "\n", 1);
	}
	free(cmds);
}

void		free_searches(t_search **searches)
{
	int			i;

	i = 0;
	while (searches[i])
	{
		free(searches[i]->ops);
		free(searches[i]->a.table);
		free(searches[i]->b.table);
		i++;
	}
	free(searches);
}
