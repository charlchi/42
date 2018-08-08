/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/08 08:28:27 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_minimap(t_env *env, int *img, int p)
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
			y = p * i - 1;
			while (++y < p * i + p)
			{
				x = p * j - 1;
				while (++x < p * j + p)
					img[x + y * env->w] = env->map[i][j] * 0x30405020;
			}
		}
	}
	img[(int)(env->x * p) + 0 + (int)((env->y * p) + 0) * env->w] = 0x00ffff00;
	img[(int)(env->x * p) + 0 + (int)((env->y * p) + 1) * env->w] = 0x00ffff00;
	img[(int)(env->x * p) + 1 + (int)((env->y * p) + 0) * env->w] = 0x00ffff00;
	img[(int)(env->x * p) + 1 + (int)((env->y * p) + 1) * env->w] = 0x00ffff00;
}
