/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:02 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:11:44 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	st_push(t_stack *stack, int val)
{
	stack->top++;
	stack->table[stack->top] = val;
}

int		st_peek(t_stack *stack)
{
	return (stack->table[stack->top]);
}

int		st_pop(t_stack *stack)
{
	stack->top--;
	return (stack->table[stack->top + 1]);
}

void	st_swap(t_stack *stack)
{
	int		*table;
	int		top;
	int		temp;

	table = stack->table;
	top = stack->top;
	if (top > 0)
	{
		temp = table[top - 1];
		table[top - 1] = table[top];
		table[top] = temp;
	}
}

void	st_rot(t_stack *stack, int rev)
{
	int		*table;
	int		prev;
	int		i;

	table = stack->table;
	if (rev)
	{
		prev = table[0];
		i = -1;
		while (++i < stack->top)
			table[i] = table[i + 1];
		table[i] = prev;
	}
	else
	{
		table = stack->table;
		prev = table[stack->top];
		i = stack->top + 1;
		while (--i > 0)
			table[i] = table[i - 1];
		table[0] = prev;
	}
}
