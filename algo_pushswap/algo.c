/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:53:56 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/08 08:19:58 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int argc, char **argv)
{
	t_search	**searches;
	t_env		env;

	env.argc = argc;
	env.argv = argv;
	parse_args(&env);
	searches = NULL;
	if (!is_sorted(env.a->table, env.argc - 2))
	{
		searches = (t_search **)malloc(sizeof(t_search *) * 4);
		searches[0] = quicksort_algo(env.a);
		searches[1] = min_algo(env.a);
		searches[2] = env.a->top > 4 ? NULL : recursive_algo(env.a);
		searches[3] = NULL;
		print_smallest_ops(searches);
	}
	if (searches)
		free_searches(searches);
	free(env.a->table);
	free(env.b->table);
	free(env.a);
	free(env.b);
	return (0);
}
