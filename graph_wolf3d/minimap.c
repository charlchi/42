/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:07 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_minimap(t_env * env, int *img, int ppc)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	while (++i < env->maph)
	{
		j = -1;
		while (++j < env->mapw)
		{
			y = ppc * i - 1;
			while (++y < ppc * i + ppc)
			{
				x = ppc * j - 1;
				while (++x < ppc * j + ppc)
					img[x + y * env->w] = env->map[i][j] * 0x30405020;
			}
		}
	}
	//draw player
	img[(int)(env->x * ppc) + 0 + (int)((env->y * ppc) + 0) * env->w] = 0x00ffff00;
	img[(int)(env->x * ppc) + 0 + (int)((env->y * ppc) + 1) * env->w] = 0x00ffff00;
	img[(int)(env->x * ppc) + 1 + (int)((env->y * ppc) + 0) * env->w] = 0x00ffff00;
	img[(int)(env->x * ppc) + 1 + (int)((env->y * ppc) + 1) * env->w] = 0x00ffff00;
}