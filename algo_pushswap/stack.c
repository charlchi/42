
typedef struct	s_stack
{
	int *table; // malloc to max size
	int top; // init to -1
}				t_stack;

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

void	st_push(t_stack *stack, int val)
{

}

void	st_rot(t_stack *stack)
{

}

void	st_revrot(t_stack *stack)
{
	
}

void	st_empty(t_stack *stack);
{
	return (stack->top < 0);
}
