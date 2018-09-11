/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:18:22 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cam(void)
{
	g_env->cam = (t_cam *)malloc(sizeof(t_cam));
	g_env->cam->ro = vec3new(6.0, -3.0, 15.0);
	g_env->cam->rd = vec3new(0.0, 0.0, 0.0);
	g_env->cam->la = vec3new(0.0, 0.0, 0.0);
	g_env->cam->c = vec3new(0.0, 1.0, 0.0);
	g_env->cam->u = vec3new(0.0, 1.0, 0.0);
	g_env->cam->f = vec3new(0.0, 0.0, 0.0);
	g_env->cam->r = vec3new(0.0, 0.0, 0.0);
	update_cam(g_env->cam); // setup forward, right vectors
}

void	init_scene(void)
{
	g_env->nshapes = 5;
	g_env->scene = malloc(sizeof(t_shape) * g_env->nshapes);
	g_env->scene[0].c = (t_vec3){-3.0, -5.0, 0.0};
	g_env->scene[0].vec2 = (t_vec3){0.8, 0.7, 0.5};
	g_env->scene[0].f1 = 2.0;
	g_env->scene[0].type = 0;
	g_env->scene[1].c = (t_vec3){0.0, 100.0, 0.0};
	g_env->scene[1].vec2 = (t_vec3){0.5, 0.5, 0.5};
	g_env->scene[1].f1 = 100.0;
	g_env->scene[1].type = 0;
	g_env->scene[2].c = (t_vec3){0.0, -1000.0, -10.0};
	g_env->scene[2].vec2 = (t_vec3){0.4, 0.4, 0.4};
	g_env->scene[2].vec1 = (t_vec3){0.0, 0.1, -1.0};
	g_env->scene[2].f1 = 10.0;
	g_env->scene[2].type = 1;
	g_env->scene[3].c = (t_vec3){0.0, -3.0, 0.0};
	g_env->scene[3].vec2 = (t_vec3){0.6, 0.8, 0.4};
	g_env->scene[3].f1 = 2.0;
	g_env->scene[3].type = 0;
	g_env->scene[4].c = (t_vec3){3.0, -1.0, 0.0};
	g_env->scene[4].vec2 = (t_vec3){0.4, 0.2, 1.0};
	g_env->scene[4].f1 = 2.0;
	g_env->scene[4].type = 0;
}
