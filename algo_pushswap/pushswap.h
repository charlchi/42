# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pushswap.h                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/02 12:45:54 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

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

int			get_cmd(char *l, char **cmds);
void		parse_args(t_stack *a, t_stack *b, int argc, char **argv)
int			valid_nums(int argc, char **argv);
int			valid_dups(int argc, char **argv);
void		exit_error(void);

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