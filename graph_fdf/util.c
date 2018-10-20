/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:56:19 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 16:58:50 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_env *env)
{
	env->w = 800;
	env->h = 800;
	env->x = 0.0;
	env->y = 0.0;
	env->z = -(env->mapw > env->maph ? env->mapw : env->maph) / 2.0;
	env->img = NULL;
	env->scale = 0.01;
	env->rotx = 22.0 / 7.0;
	env->roty = 0.0;
	env->rotz = 2.5;
	env->color = 0x0f089050;
	env->points = (t_vec3 *)malloc(sizeof(t_vec3) * (env->mapw) * (env->maph));
}
