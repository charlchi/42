/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:54:07 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/31 13:43:39 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int argc, char **argv)
{
	t_env		env;

	env.argc = argc;
	env.argv = argv;
	parse_args(&env);
	run_checker(env.a, env.b);
	free(env.a->table);
	free(env.b->table);
	free(env.a);
	free(env.b);
	return (0);
}

void	run_checker(t_stack *a, t_stack *b)
{
	char		*l;
	char		**cmds;
	int			cmd;

	if (!(cmds = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ')))
		exit_error("");
	while (get_next_line(0, &l))
	{
		if ((cmd = get_cmd(l, cmds)))
			do_cmd(a, b, cmd);
		else
			exit_error("");
	}
	if (is_sorted(a->table, a->top) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_strstrfree(cmds);
}

int		get_cmd(char *l, char **cmds)
{
	int		i;

	i = 0;
	while (cmds[i])
	{
		if (ft_strcmp(l, cmds[i]) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}
