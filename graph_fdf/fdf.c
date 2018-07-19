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

void	*get_mlx(void)
{
	static void		*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}

// raytracing on the CPU, probably not a great idea...
/*
int		mainImage(int x, int y, t_env *env)
{
	float uvx = ((float)x / (float)env->width) * ((float)env->width/(float)env->height);
	//float uvx = ((float)x / (float)env->width);
	float uvy = (float)y / (float)env->height;
	t_vec3 ro = vec3new(0.0, 0.0, -5.0);
	t_vec3 rd = vec3new(uvx - 0.5 - ro.x, uvy - 0.5 - ro.y, 0.0 - ro.z);
	t_vec3 p = vec3new(0.2*sin(2.0*g), 0.3*sin(3.0*g), 2.5 - 5.0*sin((2.8+g)*2.0));
	


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
		if (x>0&&x<env->width&&y>0&&y<env->height)
			img[x + y * env->width] = 0x00005050 + 0x00000001 * (-dy);
		step += 0.01;
	}
}

float g = 0.0;
int		draw(void *p)
{
	t_env			*env;
	char 			*data;
	int				*dword;
	int				bpp;
	int				sl;
	int				endian;

	g += 0.01;
	env = (t_env *)p;
	if (!env->img)
		if (!(env->img = mlx_new_image(get_mlx(), env->width, env->height)))
			exit(0);
	data = mlx_get_data_addr(env->img, &bpp, &sl, &endian);
	dword = (int *)data;
	int i = 0;
	while (i < env->height * env->width)
	{
		dword[i++] = 0x00000000;
	}
	//t_vec3 ro = vec3new(0.0, 0.0, -10.0);
	t_vec3 pt;
	float x[env->maph][env->mapw];
	float y[env->maph][env->mapw];
	int j;
	i = -1;
	while (++i < env->maph)
	{
		j = -1;
		while (++j < env->mapw)
		{

			float xo = (float)j / (float)env->mapw - 0.5;
			xo = xo * (float)env->mapw/(float)env->maph;
			float yo = (float)i / (float)env->maph - 0.5;
			pt.x = (xo * cos(env->rot) - yo * sin(env->rot)) + env->x / (float)env->mapw;
			pt.z = (xo * sin(env->rot) + yo * cos(env->rot)) + env->y / (float)env->maph;
			pt.y = env->z + (float)env->map[i][j] * -env->scale;
			t_vec3 ro = vec3new(0.0, 0.0, -10.0);
			vec3norm(&pt);
			float len = vec3len(&ro) / cos(vec3angle(&pt, &ro));
			vec3scale(&pt, len);
			x[i][j] = env->width  / 2 + (int)(pt.x * env->mapw);
			y[i][j] = env->height / 2 + (int)(pt.y * env->maph);
		}
	}
	i = -1;
	while (++i < env->maph - 1)
	{
		j = -1;
		while (++j < env->mapw - 1)
		{
			draw_line(x[i][j], y[i][j], x[i+1][j], y[i+1][j], dword, env);
			draw_line(x[i][j], y[i][j], x[i][j+1], y[i][j+1], dword, env);
			draw_line(x[i+1][j], y[i+1][j], x[i+1][j+1], y[i+1][j+1], dword, env);
			draw_line(x[i][j+1], y[i][j+1], x[i+1][j+1], y[i+1][j+1], dword, env);
		}
	}

	mlx_put_image_to_window(get_mlx(), env->win, env->img,0,0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*env;


	env = malloc(sizeof(t_env));
	parse_args(env, argc, argv);
		env->width = 800;
	env->height = 800;
	env->x = 0.0;
	env->y = -env->mapw * 2.0;
	env->z = 0.2;
	env->scale = 0.01;
	env->rot = 0.0;
	printf("----------------------------------------------->done parsing args\n");
	if (!(env->mlx = get_mlx()))
		exit(0);
	if (!(env->win = mlx_new_window(get_mlx(), env->width, env->height, "FDF")))
		exit(0);
	if (!(env->img = mlx_new_image(get_mlx(), env->width, env->height)))
		exit(0);
	printf("----------------------------------------------->mlx init\n");
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, draw_loop, env);
	printf("----------------------------------------------->looping\n");
	mlx_loop(env->mlx);
	if (env) free(env);
	exit(0);
}
