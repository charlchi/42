/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/31 13:21:28 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	handle_input(t_env *env)
{
	float dis;
	float rot;
	float focal;
	float oldx = env->x;
	float oldy = env->y;

	long micro = getMicrotime();
	env->dt = (micro - env->pt) / 1000.0;
	env->pt = micro;
	dis = 0.004;
	//if (env->keys[XK_w] + env->keys[XK_s] + env->keys[XK_d] + env->keys[XK_a] > 1)
		//dis /= 1.41421;
	rot = 0.004;
	focal = 0.01;
	//env->map[(int)(env->y + dis * cos(env->rot))][(int)(env->x + dis * cos(env->rot))] > 0;
	if (env->keys[XK_w] || env->keys[XK_s])
	{
		env->x += dis * cos(env->rot) * env->dt * (env->keys[XK_s] ? -1 : 1);
		env->y += dis * sin(env->rot) * env->dt * (env->keys[XK_s] ? -1 : 1);
	}
	if (env->keys[XK_d] || env->keys[XK_a])
	{
		env->x += dis * cos(env->rot + 1.7) * env->dt * (env->keys[XK_a] ? -1 : 1);
		env->y += dis * sin(env->rot + 1.7) * env->dt * (env->keys[XK_a] ? -1 : 1);
	}
	env->x = env->map[(int)oldy][(int)env->x] > 0 ? oldx : env->x;
	env->y = env->map[(int)env->y][(int)oldx] > 0 ? oldy : env->y;
	env->rot -= ((env->keys[XK_Left]) ? rot : 0.0) * env->dt;
	env->rot += ((env->keys[XK_Right]) ? rot: 0.0) * env->dt;
	env->focal -= env->keys[XK_r] ? focal : 0.0;
	env->focal += env->keys[XK_f] ? focal : 0.0;
}


int gtime = 0;
int		draw_loop(void *p)
{
	t_env		*env;
	gtime++;
	env = (t_env *)p;
	handle_input(env);
	//mlx_clear_window(env->mlx, env->win);
	printf("%d\n", gtime);
	draw(p);
	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

int		key_up_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	env->keys[key] = 0;
	if (key == 13)
		env->keys[XK_w] = 0;
	if (key == 0)
		env->keys[XK_a] = 0;
	if (key == 1)
		env->keys[XK_s] = 0;
	if (key == 2)
		env->keys[XK_d] = 0;
	if (key == 15)
		env->keys[XK_r] = 0;
	if (key == 3)
		env->keys[XK_f] = 0;
	if (key == 123)
		env->keys[XK_Left] = 0;
	if (key == 124)
		env->keys[XK_Right] = 0;
	if (key == XK_Escape || key == 53)
		exit(0);
	return (0);
}

int		key_down_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	env->keys[key] = 1;
	if (key == 13)
		env->keys[XK_w] = 1;
	if (key == 0)
		env->keys[XK_a] = 1;
	if (key == 1)
		env->keys[XK_s] = 1;
	if (key == 2)
		env->keys[XK_d] = 1;
	if (key == 15)
		env->keys[XK_r] = 1;
	if (key == 3)
		env->keys[XK_f] = 1;
	if (key == 123)
		env->keys[XK_Left] = 1;
	if (key == 124)
		env->keys[XK_Right] = 1;
	if (key == XK_Escape || key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int y, int x, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	return (0);
}

int		mouse_move_hook(int y, int x, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	return (0);
}
