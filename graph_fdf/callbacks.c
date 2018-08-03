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

#include "fdf.h"

int		draw_loop(void *p)
{
	t_env		*env;

	env = (t_env *)p;
	//mlx_clear_window(env->mlx, env->win);
	draw(p);
	usleep(2000);
	return (0);
}

int		key_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	if (key == 113)
		env->x += 2.0;
	if (key == 97)
		env->x -= 2.0;
	if (key == 119)
		env->y -= 2.0;
	if (key == 115)
		env->y += 2.0;
	if (key == 101)
		env->z -= 2.0;
	if (key == 100)
		env->z += 2.0;
	if (key == 114)
		env->rotx += 22.0/7.0/8.0;
	if (key == 102)
		env->roty += 22.0/7.0/8.0;
	if (key == 118)
		env->rotz += 22.0/7.0/8.0;
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	if (button == 4) env->scale += 0.2;
	if (button == 5) env->scale -= 0.2;
	printf("Mouse in Win, button %d at %dx%d.\n", button, x, y);
	return (0);
}