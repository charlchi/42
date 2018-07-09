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
	int			*ops;
	t_search	**searches;
	t_stack		a;
	t_stack		b;

	parse_args(&a, &b, argc, argv);
	if (argc == 2)
		return (0);
	
	searches = (t_search **)malloc(sizeof(t_search *) * 3);
	searches[0] = min_algo(&a, &b);
	searches[1] = recursive_algo(&a, &b);
	searches[2] = NULL;
	print_smallest_ops(searches);
	print_stack(&searches[0]->a);
	free_searches(searches);
	free(a.table);
	free(b.table);
	return (0);
}
