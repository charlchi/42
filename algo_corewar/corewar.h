/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:28:36 by mgerber           #+#    #+#             */
/*   Updated: 2018/09/11 14:55:32 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_process
{
	int			waitcycles;
	int			live_flag;
	int			pc;
	int			carry;
	char		reg[REG_NUMBER][REG_SIZE];
	void		*next;
}				t_process;

typedef struct	s_player
{
	int			number;
	int			lives;
	int			last_live;
	int			prog_size;
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
}				t_player;

typedef struct	s_env
{
	int			numplayers;
	t_player	players[MAX_PLAYERS];
	t_process	*first;
	char		vm[MEM_SIZE];
	int			cycles;
	int			cycle_to_die;
	int			lives;
}				t_env;

#endif