
#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	int *table;
	int top;
}				t_stack;

int		st_pop(t_stack *stack);
void	st_push(t_stack *stack, int val);
void	st_swap(t_stack *stack);
void	st_rot(t_stack *stack);
void	st_revrot(t_stack *stack);

#endif
