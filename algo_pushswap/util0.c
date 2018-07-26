/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:49 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:12:18 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack(t_stack *stack, int size)
{
	if (!(stack->table = (int *)malloc(sizeof(int) * size)))
		exit_ps();
	stack->top = -1;
}

void	copy_stack(t_stack *st, t_stack *cp)
{
	int		i;

	i = 0;
	while (i <= st->top)
	{
		cp->table[i] = st->table[i];
		i++;
	}
	cp->top = st->top;
}

int		is_sorted(int *table, int length)
{
	int		i;

	i = length;
	while (i > 0)
	{
		if (table[i] > table[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	int		i;

	i = 0;
	while (i <= stack->top)
	{
		ft_putnbr(stack->table[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	exit_ps(void)
{
	write(2, "Error\n", 7);
	exit(0);
}
