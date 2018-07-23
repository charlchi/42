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

void	draw_line(float x1, float y1, float x2, float y2, int* img, t_env *env)
{
	float step = 0.0;
	float dx = x1 - x2;
	float dy = y1 - y2;
	int x;
	int y;
	while (step <= 1.0)
	{
		x = (int)x1 - (int)(step*dx);
		y = (int)y1 - (int)(step*dy);
		if (x>0&&x<env->w&&y>0&&y<env->h)
			img[x + y * env->w] = 0x00009050 + 1 * (-dy);
		step += 0.01;
	}
}

float g = 0.0;
int		draw(void *p)
{
	t_env			*env;
	int				*img;
	int				i;
	int				j;

	g += 0.01;
	env = (t_env *)p;
	img = get_img(env);
	clear_img(img, env->w, env->h, 0x00000000);
	t_vec3 ro = vec3new(0.0, 0.0, -10.0);
	t_vec3 rd;
	
	float x[env->maph][env->mapw];
	float y[env->maph][env->mapw];
	
	i = -1;
	while (++i < env->maph)
	{
		j = -1;
		while (++j < env->mapw)
		{
			rd.x = (float)j - (env->mapw / 2);
			rd.y = (float)i - (env->maph/ 2);
			rd.z = ((float)env->map[i][j]) * env->scale;
			
			vec3rot(&rd, env->rotx, env->roty, env->rotz);
			
			rd.x = (rd.x / (float)env->mapw);
			rd.x = rd.x * (float)env->mapw/(float)env->maph;
			rd.y = (rd.y / (float)env->maph);
			rd.z = ((rd.z ) / 15.0) - 0.5;
			rd.z += (env->z / 15.0);
			rd.x += env->x / (float)env->mapw;
			rd.y += env->y / (float)env->maph;
			

			
			/*
			t_vec3 lookat = vec3new(0.0, 0.0, 0.0);
			t_vec3 f = vec3sub(&lookat, &ro);
			vec3norm(&f);
			vec3scale(&f, env->z);
			t_vec3 yup = vec3new(0.0, 1.0, 0.0);
			t_vec3 r = vec3cross(&yup, &f);
			vec3norm(&r);
			t_vec3 u = vec3cross(&f, &r);

			t_vec3 c = vec3add(&ro, &f);
			vec3scale(&r, rd.x);
			vec3scale(&u, rd.z);
			t_vec3 is = vec3add(&c, &r);
			is = vec3add(&is, &u);
			rd = vec3sub(&is, &ro);*/
			
			// convert from 3d world to 2d screen
			vec3norm(&rd);
			float len = vec3len(&ro) / cos(vec3angle(&rd, &ro));
			vec3scale(&rd, len);

			x[i][j] = env->w  / 2 + (int)(rd.x * env->mapw);
			y[i][j] = env->h / 2 + (int)(rd.y * env->maph);
		}
	}
	i = -1;
	while (++i < env->maph - 1)
	{
		j = -1;
		while (++j < env->mapw - 1)
		{
			draw_line(x[i][j], y[i][j], x[i+1][j], y[i+1][j], img, env);
			draw_line(x[i][j], y[i][j], x[i][j+1], y[i][j+1], img, env);
			draw_line(x[i+1][j], y[i+1][j], x[i+1][j+1], y[i+1][j+1], img, env);
			draw_line(x[i][j+1], y[i][j+1], x[i+1][j+1], y[i+1][j+1], img, env);
		}
	}

	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

void 	*get_mlx(void)
{
	static void 	*mlx;

	if (!mlx)
		if (!(mlx = mlx_init()))
			exit_error("mlx_init()");
	return (mlx);
}

void	exit_error(char *s)
{
	ft_putstr("Error: ");
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = malloc(sizeof(t_env));
	parse_args(env, argc, argv);
	env->w = 600;
	env->h = 600;
	env->x = 0.0;
	env->y = 0.0;
	env->z = 10.0;
	env->scale = 0.01;
	env->rotx = 0.0;
	env->roty = 0.0;
	env->rotz = 0.0;
	if (!(env->mlx = get_mlx()))
		exit_error("get_mlx()");
	if (!(env->win = get_win(env->w, env->h, "FDF")))
		exit_error("get_win()");
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env) free(env);
	exit(0);
}
