# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    algo.c                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/02 12:45:54 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <pushswap.h>

int main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	// check errors function check_errors(argc, argv)
	if (argc < 2){}
		// error
	if (!valid_args(argc, argv)){}
		// error
	// add malloc guards
	a.table = (int *)malloc(sizeof(int) * (argc - 1));
	b.table = (int *)malloc(sizeof(int) * (argc - 1));
	a.top = 0;
	b.top = 0;

	// push all args onto stack after error checking
	int			i;
	i = argc - 1;
	while (i > 0)
	{
		st_push(&a, ft_atoi(argv[i]));
		i--;
	}
	// read from stdin
	
	char		*l;
	char		**cmds;
	int			contains = 0;
	int			i;
	// get_commands();
	if (!(cmds = ft_strsplit("sa sb ss pa pb pb ra rb rr rra rrb rrr", ' '))){}
		// error-
	while (get_next_line(0, &l))
	{
		// create function that checks whether line contains cmds
		// void	is_cmd(char *l, char **cmds);
		if (is_cmd(l, cmds))
		{
			// do the operation to the stacks;
		}
		else
		{
			// error on non-empty, non-command line,
			// otherwise just break;
		}
	}
	if (is_sorted(a.table) && is_empty(b))
		print("OK\n");
	else 
		print("KO\n");
}
