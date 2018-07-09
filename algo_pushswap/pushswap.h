/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:21 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:11:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

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

void		run_checker(t_stack *a, t_stack *b);
int			get_cmd(char *l, char **cmds);

int			is_sorted(int *table, int length);
void		do_cmd(t_stack *a, t_stack *b, int cmd);
void		pushswap_cmd(t_stack *a, t_stack *b, int cmd);
void		rot_cmd(t_stack *a, t_stack *b, int cmd);
void		parse_args(t_stack *a, t_stack *b, int argc, char **argv);
int			valid_nums(int argc, char **argv);
int			valid_dups(int argc, char **argv);
void		print_stack(t_stack *stack);
void		exit_error(void);
void		copy_stack(t_stack *st, t_stack *cp);
void		init_stack(t_stack *stack, int size);

typedef struct	s_search
{
	int		n;
	int		*ops;
	t_stack	a;
	t_stack	b;
}				t_search;

t_search	*malloc_search(t_stack *a, t_stack *b);
void		search_do_op(t_search *search, int op);
void		print_smallest_ops(t_search **ss);
void		free_searches(t_search **searches);
t_search	*min_algo(t_stack *a, t_stack *b);
int			get_min_stack(t_stack *stack);

#endif
