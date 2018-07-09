/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:54:16 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:09:53 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_cmd(t_stack *a, t_stack *b, int cmd)
{
	if (cmd >= PS_SA && cmd <= PS_PB)
		pushswap_cmd(a, b, cmd);
	else if (cmd >= PS_RA && cmd <= PS_RRR)
		rot_cmd(a, b, cmd);
}

void	pushswap_cmd(t_stack *a, t_stack *b, int cmd)
{
	if (cmd == PS_SA)
		st_swap(a);
	else if (cmd == PS_SB)
		st_swap(b);
	else if (cmd == PS_SS)
	{
		st_swap(a);
		st_swap(b);
	}
	else if (cmd == PS_PA)
	{
		if (b->top >= 0)
			st_push(a, st_pop(b));
	}
	else if (cmd == PS_PB)
	{
		if (a->top >= 0)
			st_push(b, st_pop(a));
	}
}

void	rot_cmd(t_stack *a, t_stack *b, int cmd)
{
	if (cmd == PS_RA)
		st_rot(a, 0);
	else if (cmd == PS_RB)
		st_rot(b, 0);
	else if (cmd == PS_RR)
	{
		st_rot(a, 0);
		st_rot(b, 0);
	}
	else if (cmd == PS_RRA)
		st_rot(a, 1);
	else if (cmd == PS_RRB)
		st_rot(b, 1);
	else if (cmd == PS_RRR)
	{
		st_rot(a, 1);
		st_rot(b, 1);
	}
}
