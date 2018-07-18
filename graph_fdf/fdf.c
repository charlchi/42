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

//float g = 12770.0;
float g = 100.0001;

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

int		draw(void *p)
{
	g+=0.01155456;
	t_env			*env;
	char 			*data;
	int				*dword;
	int				bpp;
	int				sl;
	int				endian;

	env = (t_env *)p;
	if (!env->img)
		if (!(env->img = mlx_new_image(get_mlx(), env->width, env->height)))
			exit(0);
	data = mlx_get_data_addr(env->img, &bpp, &sl, &endian);
	dword = (int *)data;
	/*
	 * do drawing here
	 *
	 */
	int i = 0;
	while (i < env->height * env->width)
	{
		dword[i++] = 0x00000000;
	}
	t_vec3 ro = vec3new(0.0, 0.0, -5.0);
	t_vec3 pt;
	int x;
	int y;
	float step = g;
	while (step < g + 1.4)
	{
		pt.x = sin(g*step)* (sin(cos(2.8+(g+step)))) * ((sin(cos(2.8+(g+step))))* (sin(cos(2.8+(g+step)))));
		pt.y = cos(step*g)* (sin(cos(2.8+(g+step)))) * cos(step*g) * cos(step*g);
		pt.z = 5.0 - 1.0 * (sin(cos(2.8+(g+step))));
		vec3norm(&pt);
		float len = vec3len(&ro) / cos(vec3angle(&pt, &ro));
		vec3scale(&pt, len); // point still between -0.5 and 0.5
		x = env->width / 2 + (int)(pt.x * env->width * 0.5);
		y = env->height / 2 + (int)(pt.y * env->height * 0.5);
		if (x>0&&x<env->width&&y>0&&y<env->height)
		{
			dword[(x+0) + (y+0) * env->width] += 0x01020304 * pt.z;
			dword[(x+0) + (y+1) * env->width] += 0x01020304 * pt.z;
			dword[(x+1) + (y+0) * env->width] += 0x01020304 * pt.z;
			dword[(x+1) + (y+1) * env->width] += 0x01020304 * pt.z;
		}
		step += 0.001;
	}
	// clear screen

	mlx_put_image_to_window(get_mlx(), env->win, env->img,0,0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*env;


	env = malloc(sizeof(t_env));
	env->width = 800;
	env->height = 800;
	parse_args(env, argc, argv);
	printf("----------------------------------------------->done parsing args\n");
	if (!(env->mlx = get_mlx()))
		exit(0);
	if (!(env->win = mlx_new_window(get_mlx(), env->width, env->height, "FDF")))
		exit(0);
	if (!(env->img = mlx_new_image(get_mlx(), env->width, env->height)))
		exit(0);
	mlx_mouse_hook(env->win, mouse_hook, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, draw_loop, env);
	printf("----------------------------------------------->looping\n");
	mlx_loop(env->mlx);
	if (env) free(env);
	exit(0);
}
