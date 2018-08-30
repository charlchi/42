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
	env->keys[(int)key] = 1;
}

void keysup(unsigned char key, int x, int y) {
	env->keys[(int)key] = 0;
}

void mouse(int button, int state, int x, int y) {

}

void		handle_input(void)
{
	if (env->keys['r']) env->cam->ro->y += 2.0;
	if (env->keys['f']) env->cam->ro->y -= 2.0;
	if (env->keys['a']) env->cam->ro->x += 2.0;
	if (env->keys['d']) env->cam->ro->x -= 2.0;
	if (env->keys['w']) env->cam->ro->z += 2.0;
	if (env->keys['s']) env->cam->ro->z -= 2.0;
	if (env->keys['g']) env->cam->la->y += 2.0;
	if (env->keys['j']) env->cam->la->y -= 2.0;
	if (env->keys['y']) env->cam->la->x += 2.0;
	if (env->keys['h']) env->cam->la->x -= 2.0;
	if (env->keys['i']) env->cam->la->z += 2.0;
	if (env->keys['k']) env->cam->la->z -= 2.0;
	update_cam(env->cam);
}

void		draw_loop(void)
{
	long		micro;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	micro = get_micro_time();
	env->dt = (micro - env->pt) / 1000.0;
	env->pt = micro;
	handle_input();
	draw();
	glutSwapBuffers();
	glFlush();
}