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
	printf("Key in Win1 : %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	printf("Mouse in Win, button %d at %dx%d.\n", button, x, y);
	return (0);
}