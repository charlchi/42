/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:22:23 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		draw_loop(void *p)
{
	t_env		*env;
	long		micro;

	env = (t_env *)p;
	micro = get_micro_time();
	env->dt = (micro - env->pt) / 1000.0;
	env->pt = micro;
	handle_input(env);
	draw(p);
	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

int		key_up_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	env->keys[abs(key)] = 0;
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
	env->keys[abs(key)] = 1;
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
