/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/31 11:42:12 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int texwidth = 640;
int tex[640][640];
int ftex[640][640];

void	setup_cam(t_env *env, t_cam *cam, int *img, int x)
{
	cam->sweep = (float)x / (float)env->h * 1.0 - 0.5;
	cam->angle = atan(cam->sweep / env->focal);
	cam->rx = cos(env->rot + cam->angle);
	cam->ry = sin(env->rot + cam->angle);
	cam->step = 0.01;
	while (!env->map[(int)(env->y + cam->step * cam->ry)][(int)(env->x + cam->step * cam->rx)])
		cam->step += 0.01;
	cam->hitx = (int)(env->x + cam->step * cam->rx);
	cam->hity = (int)(env->y + cam->step * cam->ry);
	cam->side = cam->hity != (int)(env->y + (cam->step - 0.01) * cam->ry) ? 0 : 1;
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
	float	temp;

	y = cam->ds;
	while (y <= cam->de)
	{
		ytex = abs((int)((y + cam->h - env->h / 2) / cam->h * texwidth) / 2);
		sidescale = cam->side ? cam->hity - (env->y + cam->ry) : cam->hitx - (env->x + cam->rx);
		xtex = abs((int)(sidescale * texwidth));
		img[x + y * env->w] = tex[ytex][xtex];
		y++;
	}
}

void	draw_floor(t_env *env, t_cam *cam, int *img, int x)
{
	int		y;
	int		ytex;
	int		xtex;
	float	temp;

	y = cam->de + 1;
	while (y < env->h - 1)
	{
		cam->step =  env->h / (2.0 * (y+0) - env->h) / get_ray_dist(cam) * env->focal;
		ytex = (int)(fabs((env->y + cam->step * cam->ry) -
			(int)(env->y + cam->step * cam->ry)) * texwidth);
		xtex = (int)(fabs((env->x + cam->step * cam->rx) -
			(int)(env->x + cam->step * cam->rx)) * texwidth);
		img[x + (env->h-y) * env->w] = ((int)(x * env->x) & (int)(y * env->y));
		img[x + y          * env->w] = ((int)(x * env->x) & (int)(y * env->y));
		y++;
	}
}
		
int		draw(void *p)
{
	t_env			*env;
	int				*img;
	t_cam			*cam;
	int				x;
	int				y;

	env = (t_env *)p;
	cam = env->cam;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0x00000000);
	x = 0;
	while (x < env->w)
	{
		setup_cam(env, cam, img, x);
		draw_walls(env, cam, img, x);
		draw_floor(env, cam, img, x);
		x++;
	}
	draw_minimap(env, img, 2);
	return (0);
}

int		main(int argc, char **argv)
{
	int i1,i2,i3;
	int widthw;
	int heighth;
	void	*wallim;
	int		*wallimdata;
	void	*floorim;
	int		*floorimdata;
	//xpmimage = NULL;
	wallim = mlx_xpm_file_to_image(get_mlx(), "test.xpm", &widthw, &heighth);
	wallimdata = (int *)(mlx_get_data_addr(wallim, &i1, &i2, &i3));
	floorim = mlx_xpm_file_to_image(get_mlx(), "floor.xpm", &widthw, &heighth);
	floorimdata = (int *)(mlx_get_data_addr(floorim, &i1, &i2, &i3));
	int j;
	int i = 0;
	while (i < texwidth)
	{
		j = 0;
		while (j < texwidth)
		{
			tex[i][j] = wallimdata[j + i * texwidth];
			ftex[i][j] = floorimdata[j + i * texwidth];
			j++;
		}
		i++;
	}

	t_env		*env;
	t_cam		*cam;

	env = malloc(sizeof(t_env));
	cam = malloc(sizeof(t_cam));
	env->cam = cam;
	parse_args(env, argc, argv);
	env->w = 1000;
	env->h = 1000;
	env->x = 5.0;
	env->y = 5.0;
	env->rot = 0.0;
	env->focal = 0.7;
	env->pt = get_micro_time();
	if (!(env->mlx = get_mlx()) || !(env->win = get_win(env->w, env->h, "wolf3d")))
		exit_error("get_win()");
	//clear_img(get_img(&env->img, env->w, env->h), env->w, env->h, 0x0000000);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, mouse_move_hook, env);
	mlx_hook(env->win, 2, 1L << 0, key_down_hook, env);
	mlx_key_hook(env->win, key_up_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env)
		free(env);
	exit(0);
}
