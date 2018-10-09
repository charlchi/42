/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:11 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/02 14:58:24 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	parse_args(t_env *env)
{
	int			i;
	int			split;

	env->argv++;
	env->argc--;
	split = 0;
	if (env->argc == 1)
	{
		split = 1;
		env->argv = ft_strsplit(env->argv[0], ' ');
		env->argc = ft_strstrlen(env->argv);
	}
	if (!valid_nums(env) || !valid_dups(env))
		exit_ps();
	if (!(env->a = (t_stack *)malloc(sizeof(t_stack))))
		exit_ps();
	if (!(env->b = (t_stack *)malloc(sizeof(t_stack))))
		exit_ps();
	init_stack(env->a, env->argc + 1);
	init_stack(env->b, env->argc + 1);
	i = env->argc - 1;
	while (i >= 0)
		st_push(env->a, ft_atoi(env->argv[i--]));
	if (split == 1)
		free_args(env->argv);
}

int		valid_nums(t_env *env)
{
	int		i;
	int		j;
	char	c;

	i = 0;
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

	i = 0;
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

void	free_args(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	if (argv)
		free(argv);
}