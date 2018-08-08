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

float		get_ray_dist(t_cam *cam)
{
	float 				x;
	float 				y;

	x = cam->rx;
	y = cam->ry;
	return (sqrt(y * y + x * x * cos(cam->angle)));
}

long		get_micro_time(void)
{
	struct timeval		currenttime;

	gettimeofday(&currenttime, NULL);
	return (currenttime.tv_sec * (int)1e6 + currenttime.tv_usec);
}

void		handle_input(t_env *env)
{
	float				oldx;
	float				oldy;
	long				micro;

	oldx = env->x;
	oldy = env->y;
	micro = get_micro_time();
	env->dt = (micro - env->pt) / 1000.0;
	env->pt = micro;
	if (env->keys[XK_w] || env->keys[XK_s])
	{
		env->x += 0.004 * cos(env->rot) * env->dt * (env->keys[XK_s] ? -1 : 1);
		env->y += 0.004 * sin(env->rot) * env->dt * (env->keys[XK_s] ? -1 : 1);
	}
	if (env->keys[XK_d] || env->keys[XK_a])
	{
		env->x += 0.004 * cos(env->rot + 1.7) * env->dt * (env->keys[XK_a] ? -1 : 1);
		env->y += 0.004 * sin(env->rot + 1.7) * env->dt * (env->keys[XK_a] ? -1 : 1);
	}
	env->x = env->map[(int)oldy][(int)env->x] > 0 ? oldx : env->x;
	env->y = env->map[(int)env->y][(int)oldx] > 0 ? oldy : env->y;
	env->rot -= ((env->keys[XK_Left]) ? 0.004 : 0.0) * env->dt;
	env->rot += ((env->keys[XK_Right]) ? 0.004: 0.0) * env->dt;
	env->focal -= env->keys[XK_r] ? 0.01 : 0.0;
	env->focal += env->keys[XK_f] ? 0.01 : 0.0;
}
