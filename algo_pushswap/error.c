# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.c                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/02 12:45:54 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "pushswap.h"

void	parse_args(t_stack *a, t_stack *b, int argc, char **argv)
{
	int			i;

	if (argc < 2)
		exit_error();
	if (!valid_nums(argc, argv))
		exit_error();
	if (!valid_dups(argc, argv))
		exit_error();
	if (!(a->table = (int *)malloc(sizeof(int) * (argc - 1))))
		exit_error();
	if (!(b->table = (int *)malloc(sizeof(int) * (argc - 1))))
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

int		valid_nums(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (c == '-' || c == '+')
			j++;
		while ((c = argv[i][j]))
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

int		valid_dups(int argc, char **argv)
{
	int		i;
	int		j;
	
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j] < 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	exit_error(void)
{
	write(2, "Error\n", 7);
	exit();
}