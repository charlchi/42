# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pushswap.c                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/02 12:45:54 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "pushswap.h"

void	do_cmd(t_stack *a, t_stack *b, int cmd)
{
	if (cmd == PS_SA)
		st_swap(a);
	else if (cmd == PS_SB)
		st_swap(b);
	else if (cmd == PS_SS)
	{
		st_swap(a);
		st_swap(b);
	}
	else if (cmd == PS_PA)
	else if (cmd == PS_PB)
	else if (cmd == PS_RA)
	else if (cmd == PS_RB)
	else if (cmd == PS_RR)
	else if (cmd == PS_RRA)
	else if (cmd == PS_RRB)
	else if (cmd == PS_RRR)

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

void	init_stacks(t_stack *a, t_stack *b, int size)
{
	int			i;

	if (!(a->table = (int *)malloc(sizeof(int) * (size - 1))))
		exit_error();
	if (!(b->table = (int *)malloc(sizeof(int) * (size - 1))))
		exit_error();
	a->top = 0;
	b->top = 0;
	i = argc - 1;
	while (i > 0)
	{
		st_push(a, ft_atoi(argv[i]));
		i--;
	}
}