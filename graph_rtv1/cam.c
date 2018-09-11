/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:18:22 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	update_cam(t_cam *cam)
{
	vec3norm(vec3sub(cam->la, cam->ro, cam->f), cam->f);
	vec3set(cam->u, 0.0, 1.0, 0.0);
	vec3cross(cam->u, cam->f, cam->r);
	vec3cross(cam->f, cam->r, cam->u);
	vec3add(cam->ro, cam->f, cam->c);
}

void	set_raydir(float x, float y, t_cam *cam)
{
	float	uvx;
	float	uvy;
	t_vec3	up;
	t_vec3	right;

	uvx = (float)(x) / (float)g_env->w - 0.5;
	uvx *= (float)g_env->w / (float)g_env->h;
	uvy = (float)(y) / (float)g_env->h - 0.5;
	vec3scale(cam->r, &right, uvx);
	vec3scale(cam->u, &up, uvy);
	vec3add(cam->c, &right, cam->rd);
	vec3add(cam->rd, &up, cam->rd);
	vec3sub(cam->rd, cam->ro, cam->rd);
}
