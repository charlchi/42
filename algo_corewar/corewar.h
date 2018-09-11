/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:44:35 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft/libft.h"
# include "op.h"

typedef struct	s_process
{
	int			waitcycles;
	int			live_flag;
	int			pc;
	int			carry; 
	int			reg[REG_NUMBER];
	void		*next;
}				t_process;

typedef struct	s_env
{
	int			numplayers;
	//t_player	players[MAX_PLAYERS + 1];
	t_process	*first;
	char		vm[MEM_SIZE];
	int			cycles;
	int			cycle_to_die;
	int			lives;
}				t_env;

typedef struct	s_player
{
	int		number;
	int		lives;
	int		last_live;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
}				t_player;

#endif