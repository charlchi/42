
typedef struct	s_stack
{
	int *table;
	int top;
}				t_stack;

void	st_peek(t_stack *stack);
void	st_swap(t_stack *stack);
void	st_push(t_stack *stack, int val);
void	st_rot(t_stack *stack);
void	st_revrot(t_stack *stack);
void	st_empty(t_stack *stack);
