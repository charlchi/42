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

#include "rtv1.h"

void keysdown(unsigned char key, int x, int y) {
	g_env->keys[(int)key] = 1;
}

void keysup(unsigned char key, int x, int y) {
	g_env->keys[(int)key] = 0;
}

void mouse(int button, int state, int x, int y) {

}

void		handle_input(void)
{
	if (g_env->keys['r']) g_env->cam->ro->y += 2.0;
	if (g_env->keys['f']) g_env->cam->ro->y -= 2.0;
	if (g_env->keys['a']) g_env->cam->ro->x += 2.0;
	if (g_env->keys['d']) g_env->cam->ro->x -= 2.0;
	if (g_env->keys['w']) g_env->cam->ro->z += 2.0;
	if (g_env->keys['s']) g_env->cam->ro->z -= 2.0;
	if (g_env->keys['g']) g_env->cam->la->y += 2.0;
	if (g_env->keys['j']) g_env->cam->la->y -= 2.0;
	if (g_env->keys['y']) g_env->cam->la->x += 2.0;
	if (g_env->keys['h']) g_env->cam->la->x -= 2.0;
	if (g_env->keys['i']) g_env->cam->la->z += 2.0;
	if (g_env->keys['k']) g_env->cam->la->z -= 2.0;
	update_cam(g_env->cam);
}

void		draw_loop(void)
{
	long		micro;

	micro = get_micro_time();
	g_env->dt = (micro - g_env->pt) / 1000.0;
	g_env->pt = micro;
	handle_input();
	draw();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawPixels(g_env->w, g_env->h, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, g_env->imgdata);
	glutSwapBuffers();
	glFlush();
}