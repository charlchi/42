/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:07 by cmoller          ###   ########.fr       */
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
	env->dt = (micro - env->pt) / 10000.0;
	printf("%lu\n", env->dt);
	env->pt = micro;
	dis = 0.05;
	if (env->keys[XK_w] + env->keys[XK_s] + env->keys[XK_d] + env->keys[XK_a] > 1)
		dis /= 1.41421;
	rot = 0.04;
	focal = 0.01;
	//env->map[(int)(env->y + dis * cos(env->rot))][(int)(env->x + dis * cos(env->rot))] > 0;
	if (env->keys[XK_w])
	{
		env->x += dis * cos(env->rot) * env->dt;
		env->y += dis * sin(env->rot) * env->dt;
	}
	if (env->keys[XK_s])
	{
		env->x -= dis * cos(env->rot) * env->dt;
		env->y -= dis * sin(env->rot) * env->dt;
	}
	if (env->keys[XK_a] || env->keys[XK_d])
	{
		env->x += dis * cos(env->rot + 1.7) * (env->keys[XK_d] ? 1.0 : -1.0) * env->dt;
		env->y += dis * sin(env->rot + 1.7) * (env->keys[XK_d] ? 1.0 : -1.0) * env->dt;
	}
	env->x = env->map[(int)oldy][(int)env->x] > 0 ? oldx : env->x;
	env->y = env->map[(int)env->y][(int)oldx] > 0 ? oldy : env->y;
	env->rot -= (env->keys[XK_Left] ? rot : 0.0) * env->dt;
	env->rot += (env->keys[XK_Right] ? rot: 0.0) * env->dt;
	env->focal -= env->keys[XK_r] ? focal : 0.0;
	env->focal += env->keys[XK_f] ? focal : 0.0;
	XWarpPointer(((t_xvar *)get_mlx())->display, None, ((t_win_list *)(((t_xvar *)get_mlx())->win_list))->window, 0, 0, 0, 0, env->w/2, 0);
}

int		draw_loop(void *p)
{
	t_env		*env;

	env = (t_env *)p;
	//mlx_clear_window(env->mlx, env->win);
	draw(p);
	usleep(2000);
	return (0);
}

int		key_up_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	//printf("key up  : %d\n", key);
	env->keys[key] = 0;
	if (key == XK_Escape)
		exit(0);
	return (0);
}

int		key_down_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	//printf("key down: %d\n", key);
	env->keys[key] = 1;
	if (key == XK_Escape)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int y, int x, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	printf("Mouse in Win, button %d at %dx%d.\n", button, x, y);
	env->rot = (float)(y/100.0);

	return (0);
}

int		mouse_move_hook(int y, int x, void *p)
{
	t_env		*env;

	env = (t_env *)p;

	//printf("Mouse moving at %dx%d.\n", x, y);
	env->rot += (float)((y - env->h / 2)/200.0);
	
	return (0);
}