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

# include "op.h"
# include "libft/libft.h"
# include <stdlib.h>

char	*strip_asm(char **str);

typedef struct	s_process
{
	int			waitcycles;
	int			live_flag;
	int			pc;
	int			carry;
	int			reg[REG_NUMBER];
	void		*next;
}				t_process;

typedef struct	s_player
{
	int			number;
	int			lives;
	int			last_live;
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
}				t_player;

typedef struct	s_env
{

	int			numplayers;
	t_player	players[MAX_PLAYERS + 1];

	t_process	*first;
	char		vm[MEM_SIZE];
	int			cycles;
	int			cycle_to_die;
	int			lives;
}				t_env;

#endif