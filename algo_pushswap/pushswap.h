/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:10:21 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/02 15:05:22 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

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

typedef struct	s_env
{
	char	**argv;
	int		argc;
	t_stack	*a;
	t_stack	*b;
}				t_env;

typedef struct	s_search
{
	int		n;
	int		*ops;
	t_stack	a;
	t_stack	b;
}				t_search;

typedef struct	s_partition
{
	int		n;
	int		*stack;
}				t_partition;

int				st_peek(t_stack *stack);
int				st_pop(t_stack *stack);
void			st_push(t_stack *stack, int val);
void			st_swap(t_stack *stack);
void			st_rot(t_stack *stack, int rev);

void			parse_args(t_env *env);
int				valid_nums(t_env *env);
int				valid_dups(t_env *env);
void			free_args(char **argv);

void			run_checker(t_stack *a, t_stack *b);
int				get_cmd(char *l, char **cmds);
int				is_sorted(int *table, int length);
void			do_cmd(t_stack *a, t_stack *b, int cmd);
void			pushswap_cmd(t_stack *a, t_stack *b, int cmd);
void			rot_cmd(t_stack *a, t_stack *b, int cmd);
void			print_stack(t_stack *stack);
void			exit_ps(void);
void			copy_stack(t_stack *st, t_stack *cp);
void			init_stack(t_stack *stack, int size);
t_search		*malloc_search(t_stack *a);
void			search_do_op(t_search *search, int op);
void			print_smallest_ops(t_search **ss);
void			free_searches(t_search **searches);
void			free_search(t_search *search);

t_search		*min_algo(t_stack *a);
int				get_min_stack(t_stack *stack, int *ip);
int				get_max_stack(t_stack *stack, int *ip);

t_search		*recursive_algo(t_stack *a);
void			copy_search(t_search *src, t_search *dst);
void			find_permutation(t_search *gsol, t_search *s, int d, int max);
int				test_permutation(t_search *s);

t_search		*quicksort_algo(t_stack *ap);
void			partition_to_b(t_partition *bp, t_search *s);
void			partition_back_a(t_partition *a, t_partition *b, t_search *s);
void			partition_back_b(t_partition *a, t_partition *b, t_search *s);
void			partition(int i, t_partition *a, t_partition *b, t_search *s);
int				has_larger(int mid, t_stack *a);
int				has_smallereq(int mid, t_stack *a);
int				get_mid(t_stack *a, int n);
void			bubble_sort(int *tab, int size);

#endif
