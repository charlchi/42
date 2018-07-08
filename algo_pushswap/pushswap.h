
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define PS_SA 1
# define PS_SB 2
# define PS_SS 3
# define PS_PA 4
# define PS_PB 5
# define PS_RA 6
# define PS_RB 7
# define PS_RR 8
# define PS_RRA 9
# define PS_RRB 10
# define PS_RRR 11

typedef struct	s_stack
{
	int *table;
	int top;
}				t_stack;

int			st_peek(t_stack *stack);
int			st_pop(t_stack *stack);
void		st_push(t_stack *stack, int val);
void		st_swap(t_stack *stack);
void		st_rot(t_stack *stack, int rev);

// checker
void		run_checker(t_stack *a, t_stack *b);
int			get_cmd(char *l, char **cmds);

// general functions
int 		is_sorted(int *table, int length);
void		do_cmd(t_stack *a, t_stack *b, int cmd);
void		pushswap_cmd(t_stack *a, t_stack *b, int cmd);
void		rot_cmd(t_stack *a, t_stack *b, int cmd);
void		parse_args(t_stack *a, t_stack *b, int argc, char **argv);
int			valid_nums(int argc, char **argv);
int			valid_dups(int argc, char **argv);
void		print_stack(t_stack *stack);
void		exit_error(void);

// push_swap
typedef struct	s_search;
{
	int		n;
	int		*ops;
	t_stack	*a;
	t_stack	*b;
}				t_search;

void	algo_min(t_search *search);
void	algo1_algo(t_search *search);

#endif