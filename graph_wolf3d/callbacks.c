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
	printf("key up  : %d\n", key);
	if (key == 119 || key == 13) env->keys['w'] = 0;
	if (key == 115 || key == 1) env->keys['s'] = 0;
	if (key == 97  || key == 0) env->keys['a'] = 0;
	if (key == 100 || key == 2) env->keys['d'] = 0;
	if (key == 102) env->keys['f'] = 0;
	if (key == 114) env->keys['r'] = 0;
	if (key == 53)
		exit(0);
	return (0);
}

int		key_down_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	printf("key down: %d\n", key);
	if (key == 119 || key == 13) env->keys['w'] = 1;
	if (key == 115 || key == 1) env->keys['s'] = 1;
	if (key == 97  || key == 0) env->keys['a'] = 1;
	if (key == 100 || key == 2) env->keys['d'] = 1;
	if (key == 102) env->keys['f'] = 1;
	if (key == 114) env->keys['r'] = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	// if (button == 4) env->scale += 0.2;
	// if (button == 5) env->scale -= 0.2;
	printf("Mouse in Win, button %d at %dx%d.\n", button, x, y);
	return (0);
}