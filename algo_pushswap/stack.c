
#include "stack.h"

int		st_pop(t_stack *stack);
void	st_push(t_stack *stack, int val);
void	st_swap(t_stack *stack);
void	st_rot(t_stack *stack);
void	st_revrot(t_stack *stack);

void	st_push(t_stack *stack, int val)
{
	stack->top++;
	stack->table[stack->top] = val;
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

void	st_rot(t_stack *stack)
{
	int		*table;
	int		prev;
	int		i;

	table = stack->table;
	prev = table[stack->top];
	i = stack->top;
	while (i > 0)
	{
		table[i] = table[i - 1];
		i--;
	}
	table[0] = prev;
}

void	st_revrot(t_stack *stack)
{
	int		*table;
	int		prev;
	int		i;

	table = stack->table;
	prev = table[0];
	i = 0;
	while (i < stack->top - 1)
	{
		table[i] = table[i + 1];
		i++;
	}
	table[i] = prev;
}