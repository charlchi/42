/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:11 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:10:13 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	parse_args(t_env *env)
{
	int			i;

	if (env->argc < 2)
		exit_ps();
	if (!valid_nums(env) || !valid_dups(env))
		exit_ps();
	if (!(env->a = (t_stack *)malloc(sizeof(t_stack))))
		exit_ps();
	if (!(env->b = (t_stack *)malloc(sizeof(t_stack))))
		exit_ps();
	init_stack(env->a, env->argc - 1);
	init_stack(env->b, env->argc - 1);
	i = env->argc - 1;
	while (i > 0)
	{
		st_push(env->a, ft_atoi(env->argv[i]));
		i--;
	}
}

int		valid_nums(t_env *env)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < env->argc)
	{
		j = 0;
		c = env->argv[i][j];
		if (c == '-' || c == '+')
			j++;
		while ((c = env->argv[i][j]))
		{
			if (!(ft_isdigit(c)))
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

int		valid_dups(t_env *env)
{
	int		i;
	int		j;

	i = 1;
	while (i < env->argc - 1)
	{
		j = i + 1;
		while (j < env->argc)
		{
			if (ft_strcmp(env->argv[i], env->argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
