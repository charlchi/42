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
	if (key == 100) {env->x += 1.0; printf("[x++][%.2f]", env->x);}
	if (key ==  97) {env->x -= 1.0; printf("[x--][%.2f]", env->x);}
	if (key == 115) {env->y += 1.0; printf("[y++][%.2f]", env->y);}
	if (key == 119) {env->y -= 1.0; printf("[y--][%.2f]", env->y);}
	if (key == 103) {env->z -= 1.0; printf("[z++][%.2f]", env->z);}
	if (key == 116) {env->z += 1.0; printf("[z--][%.2f]", env->z);}
	if (key == 114) {env->rot += 22.0/7.0/2.0;}

	printf("Key in Win1 : %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *p)
{
	t_env		*env;


	env = (t_env *)p;
	if (button == 4) env->scale += 0.005;
	if (button == 5) env->scale -= 0.005;
	printf("Mouse in Win, button %d at %dx%d.\n", button, x, y);
	return (0);
}