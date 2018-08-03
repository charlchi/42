/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:00 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// raytracing on the CPU, probably not a great idea...
/*int		mainImage(int x, int y, t_env *env)
{
	float uvx = (float)x / (float)env->w;
	uvx *= (float)env->w/(float)env->h;
	float uvy = (float)y / (float)env->h;
	t_vec3 ro = vec3new(0.0, 0.0, -5.0);
	t_vec3 rd = vec3new(
		uvx - 0.5 - ro.x,
		uvy - 0.5 - ro.y,
		0.0 - ro.z
	);
	t_vec3 p = vec3new(
		0.2*sin(2.0*g),
		0.3*sin(3.0*g),
		2.5 - 5.0*sin((2.8+g)*2.0)
	);
	
	float step = 0.0;
	float dist;
	float mindis = 100000.0;
	while (step < 0.1)
	{
		p.x = 0.2*sin(2.0*(g+step));
		p.y = 0.3*sin(3.0*(g+step));
		p.z = 2.5 - 5.0*sin((2.8+(g+step))*2.0);
		dist = vec3distlp(&ro, &rd, &p);
		if (dist < mindis)
			mindis = dist;
		step += 0.01;
	}
	//printf("%f\n", dist);
	return (mindis < 0.05 ? 255 - (0x000000ff * 9.0) : 0x00000000);
	//return 0x01020304 * dist;
}*/

void	draw_line(t_vec3 p1, t_vec3 p2, t_env *env)
{
	float	step;
	float	dx;
	float	dy;
	int		x;
	int		y;

	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	step = 0.0;
	int *img = get_img(&env->img, env->w, env->h);
	while (step <= 1.0)
	{
		x = (int)p1.x - (int)(step*dx);
		y = (int)p1.y - (int)(step*dy);
		if (x > 0 && x < env->w && y > 0 && y < env->h)
			img[x + y * env->w] = 0x00ffffff;
		step += 0.01;
	}
}

float	calculate_point(t_vec3 *rd, int i, int j, t_env *env)
{
	float	len;
	t_vec3	ro;

	ro = vec3new(0.0, 0.0, -10.0);
	rd->x = (float)j - (env->mapw / 2);
	rd->y = (float)i - (env->maph/ 2);
	rd->z = ((float)env->map[i][j]) * env->scale;
	vec3rot(rd, env->rotx, env->roty, env->rotz);
	rd->x = (rd->x / (float)env->mapw);
	rd->x = rd->x * (float)env->mapw/(float)env->maph;
	rd->y = (rd->y / (float)env->maph);
	rd->z = ((rd->z ) / 15.0) - 0.5;
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
			env->points[j + i * env->mapw].x = env->w  / 2 + (int)(rd.x * env->mapw);
			env->points[j + i * env->mapw].y = env->h / 2 + (int)(rd.y * env->maph);
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
			draw_line(env->points[(j) + (i) * env->mapw],   env->points[(j+1) + (i) * env->mapw], env);
			draw_line(env->points[(j) + (i) * env->mapw],   env->points[(j) + (i+1) * env->mapw], env);
			draw_line(env->points[(j+1) + (i) * env->mapw], env->points[(j+1) + (i+1) * env->mapw], env);
			draw_line(env->points[(j) + (i+1) * env->mapw], env->points[(j+1) + (i+1) * env->mapw], env);
		}
	}
}

int		draw(void *p)
{
	t_env			*env;
	int				*img;
	int				i;
	int				j;

	env = (t_env *)p;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0x00000000);
	get_points(env);
	draw_points(env);
	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	parse_args(env, argc, argv);
	init_env(env);
	if (!(env->mlx = get_mlx()) || !(env->win = get_win(env->w, env->h, "FDF")))
		exit_error("mlx error");
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env->points)
		free(env->points);
	if (env)
		free(env);
	exit(0);
}
