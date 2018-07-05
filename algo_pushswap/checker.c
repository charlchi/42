# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.c                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/02 12:45:54 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "pushswap.h"

int		main(int argc, char **argv)
{
	char		**cmds;
	t_stack		a;
	t_stack		b;

	parse_args(&a, &b, argc, argv);
	if (!(cmds = ft_strsplit("sa sb ss pa pb pb ra rb rr rra rrb rrr", ' ')))
		exit_error();
	run_checker(&a, &b, cmds);
	if (is_sorted(a.table) && is_empty(b))
		print("OK\n");
	else 
		print("KO\n");
	free_checker();
	return (0);
}

void	run_checker(t_stack *a, t_stack *a, char **cmds)
{
	char	*l;

	while (get_next_line(0, &l))
	{
		if ((cmd = get_cmd(l, cmds)))
			do_cmd(a, b, cmd); //TODO
		else if (ft_strcmp(l, "") == 0)
			exit_error();
		}
	}

}

// TODO put in another file
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

// TODO put in another file
void	init_stacks(t_stack *a, t_stack *b, int size)
{

}