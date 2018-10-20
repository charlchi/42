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

int		draw(void *p)
{
	t_env			*env;
	int				*img;

	env = (t_env *)p;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0x00000000);
	get_points(env);
	draw_points(env);
	return (0);
}

int		draw_loop(void *p)
{
	t_env		*env;

	env = (t_env *)p;
	draw(p);
	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

int		key_hook(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	if (key == 114 || key == 15)
		env->rotx += 22.0 / 7.0 / 8.0;
	if (key == 102 || key == 3)
		env->roty += 22.0 / 7.0 / 8.0;
	if (key == 118 || key == 9)
		env->rotz += 22.0 / 7.0 / 8.0;
	if (key == XK_Escape || key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	if (button == 4 && env->scale < 2.0)
		env->scale += 0.2 + x - x;
	if (button == 5 && env->scale > -2.0)
		env->scale -= 0.2 + y - y;
	return (0);
}
