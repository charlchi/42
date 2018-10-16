/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 15:33:27 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_vec3 p1, t_vec3 p2, t_env *env)
{
	float	step;
	int		*img;
	int		x;
	int		y;

	step = 0.0;
	img = get_img(&env->img, env->w, env->h);
	while (step <= 1.0)
	{
		x = (int)p1.x - (int)(step * (p1.x - p2.x));
		y = (int)p1.y - (int)(step * (p1.y - p2.y));
		if (x > 0 && x < env->w && y > 0 && y < env->h)
			img[x + y * env->w] = 0x00ffffff;
		step += 0.01;
	}
}

void	calculate_point(t_vec3 *rd, int i, int j, t_env *env)
{
	float	len;
	t_vec3	ro;

	ro = vec3new(0.0, 0.0, -10.0);
	rd->x = (float)j - (env->mapw / 2);
	rd->y = (float)i - (env->maph / 2);
	rd->z = ((float)env->map[i][j]) * env->scale;
	vec3rot(rd, env->rotx, env->roty, env->rotz);
	rd->x = (rd->x / (float)env->mapw);
	rd->x = rd->x * (float)env->mapw / (float)env->maph;
	rd->y = (rd->y / (float)env->maph);
	rd->z = ((rd->z) / 15.0) - 0.5;
	rd->z += (env->z / 15.0);
	rd->x += env->x / (float)env->mapw;
	rd->y += env->y / (float)env->maph;
	vec3norm(rd);
	len = vec3len(&ro) / cos(vec3angle(rd, &ro));
	vec3scale(rd, len);
}

void	get_points(t_env *env)
{
	t_vec3	rd;
	int		i;
	int		j;

	i = -1;
	while (++i < env->maph)
	{
		j = -1;
		while (++j < env->mapw)
		{
			calculate_point(&rd, i, j, env);
			env->points[j + i * env->mapw].x = env->w / 2 +
				(int)(rd.x * env->mapw);
			env->points[j + i * env->mapw].y = env->h / 2 +
				(int)(rd.y * env->maph);
		}
	}
}

void	draw_points(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->maph - 1)
	{
		j = -1;
		while (++j < env->mapw - 1)
		{
			draw_line(env->points[(j) + (i) * env->mapw],
					env->points[(j + 1) + (i) * env->mapw], env);
			draw_line(env->points[(j) + (i) * env->mapw],
					env->points[(j) + (i + 1) * env->mapw], env);
			draw_line(env->points[(j + 1) + (i) * env->mapw],
					env->points[(j + 1) + (i + 1) * env->mapw], env);
			draw_line(env->points[(j) + (i + 1) * env->mapw],
					env->points[(j + 1) + (i + 1) * env->mapw], env);
		}
	}
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	parse_args(argc, argv, env);
	init_env(env);
	if (!(env->mlx = get_mlx()))
		exit_error("mlx error");
	if (!(env->win = get_win(env->w, env->h, "FDF")))
		exit_error("mlx error");
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env->points)
		free(env->points);
	if (env)
		free(env);
	return (0);
}
