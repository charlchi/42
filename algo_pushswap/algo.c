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
	t_env		env;

	env.argc = argc;
	env.argv = argv;
	parse_args(&env);
	if (argc == 2)
		return (0);
	searches = NULL;
	if (!is_sorted(env.a->table, argc - 2))
	{
		searches = (t_search **)malloc(sizeof(t_search *) * 3);
		searches[0] = min_algo(env.a);
		searches[1] = recursive_algo(env.a);
		searches[2] = NULL;
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
