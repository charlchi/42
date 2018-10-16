/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:18:22 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	setup_cam(t_env *env, t_cam *cam, int x)
{
	cam->sweep = (float)x / (float)env->h * 1.0 - 0.5;
	cam->angle = atan(cam->sweep / env->focal);
	cam->rx = cos(env->rot + cam->angle);
	cam->ry = sin(env->rot + cam->angle);
	cam->step = 0.01;
	while (!env->map[(int)(env->y + cam->step * cam->ry)]
			[(int)(env->x + cam->step * cam->rx)])
		cam->step += 0.01;
	cam->hitx = (int)(env->x + cam->step * cam->rx);
	cam->hity = (int)(env->y + cam->step * cam->ry);
	cam->side =
		cam->hity != (int)(env->y + (cam->step - 0.01) * cam->ry) ? 0 : 1;
	cam->rx = cam->rx * cam->step;
	cam->ry = cam->ry * cam->step;
	cam->h = 0.5 * env->focal * env->h / get_ray_dist(cam);
	cam->ds = -cam->h + env->h / 2 < 0 ? 0 : -cam->h + env->h / 2;
	cam->de = cam->h + env->h / 2 >= env->h ? env->h - 1 : cam->h + env->h / 2;
}

void	draw_walls(t_env *env, t_cam *cam, int *img, int x)
{
	int		y;
	int		xtex;
	int		ytex;
	float	sidescale;

	y = cam->ds;
	while (y <= cam->de)
	{
		ytex = abs((int)((y + cam->h - env->h / 2) / cam->h * 640) / 2);
		sidescale =
			cam->side ? cam->hity - (env->y + cam->ry) :
			cam->hitx - (env->x + cam->rx);
		xtex = abs((int)(sidescale * 640));
		img[x + y * env->w] = env->tex[ytex][xtex];
		y++;
	}
}

void	draw_floor(t_env *env, t_cam *cam, int *img, int x)
{
	int		y;
	int		ytex;
	int		xtex;

	y = cam->de + 1;
	while (y < env->h - 1)
	{
		cam->step = env->h / (2.0 * (y + 0) - env->h) /
			get_ray_dist(cam) * env->focal;
		ytex = (int)(fabs((env->y + cam->step * cam->ry) -
			(int)(env->y + cam->step * cam->ry)) * 640);
		xtex = (int)(fabs((env->x + cam->step * cam->rx) -
			(int)(env->x + cam->step * cam->rx)) * 640);
		img[x + (env->h - y) * env->w] = env->ftex[ytex][xtex];
		img[x + y * env->w] = env->ftex[ytex][xtex];
		y++;
	}
}

int		draw(void *p)
{
	t_env			*env;
	int				*img;
	t_cam			*cam;
	int				x;

	env = (t_env *)p;
	cam = env->cam;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0x00000000);
	x = 0;
	while (x < env->w)
	{
		setup_cam(env, cam, x);
		draw_walls(env, cam, img, x);
		draw_floor(env, cam, img, x);
		x++;
	}
	draw_minimap(env, img, 2);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*env;
	t_cam		*cam;

	env = malloc(sizeof(t_env));
	cam = malloc(sizeof(t_cam));
	env->cam = cam;
	parse_args(argc, argv, env);
	load_images(env, "walls.xpm", "floor.xpm");
	env->w = 1000;
	env->h = 1000;
	env->x = 5.0;
	env->y = 5.0;
	env->focal = 0.7;
	env->pt = get_micro_time();
	if (!(env->mlx = get_mlx()))
		exit_error("get_mlx()");
	if (!(env->win = get_win(env->w, env->h, "wolf3d")))
		exit_error("get_win()");
	mlx_hook(env->win, 2, 1L << 0, key_down_hook, env);
	mlx_key_hook(env->win, key_up_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env)
		free(env);
	exit(0);
}
