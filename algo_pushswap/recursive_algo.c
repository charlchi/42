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

t_search	*recursive_algo(t_stack *ap, t_stack *bp)
{
	int			min;
	t_search	*s;
	t_stack		*a;
	t_stack		*b;

	s = malloc_search(ap, bp);
	a = &s->a;
	b = &s->b;
	// start off each recursive thing with a call to each command, then recurse from there
	int		len; // amount of commands in this search

	len = 1;
	while (len < 8)
	{


	}
	return s;
}