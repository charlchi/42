/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:53:56 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 08:53:59 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int argc, char **argv)
{
	t_search	**searches;
	t_stack		a;
	t_stack		b;

	parse_args(&a, &b, argc, argv);
	if (argc == 2)
		return (0);
	if (!is_sorted(a.table, argc - 2))
	{
		searches = NULL;
		searches = (t_search **)malloc(sizeof(t_search *) * 3);
		searches[0] = min_algo(&a);
		searches[1] = recursive_algo(&a);
		searches[2] = NULL;
		print_smallest_ops(searches);
	}
	//TODO REMOVE
	//print_stack(&searches[0]->a);
	if (searches)
		free_searches(searches);
	free(a.table);
	free(b.table);
	return (0);
}
