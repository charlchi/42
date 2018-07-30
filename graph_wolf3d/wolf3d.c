/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:00 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int texwidth = 32;
int tex[32][32] = {
	{1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
	{1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
	{1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 3,0,3,0, 3,0,3,0, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 0,3,0,3, 0,3,0,3, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 3,0,3,0, 3,0,3,0, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 0,3,0,3, 0,3,0,3, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 3,0,3,0, 3,0,3,0, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 0,3,0,3, 0,3,0,3, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 3,0,3,0, 3,0,3,0, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 0,3,0,3, 0,3,0,3, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, 2,1,1,1},
	{1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
	{1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
	{1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1}
};

long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

float g = 0.0;
int		draw(void *p)
{
	t_env			*env;
	int				*img;
	t_cam			*cam;
	int				i;
	int				j;
	int				x;
	int				y;

	g += 0.00001;
	env = (t_env *)p;

//TIMER___

//TIMER^^^
	cam = env->cam;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0xff0055cc);
	// handle input
	// handle keyboard input
	handle_input(env);

	//sweep screen from left to right
	x = 0;
	while (x < env->w)
	{
		cam->sweep = (float)x / (float)env->h * 1.0 - 0.5;
		//cam->angle = atan(cam->sweep / env->focal) / env->focal;
		cam->angle = atan(cam->sweep / env->focal);
		cam->rx = cos(env->rot + cam->angle);
	  	cam->ry = sin(env->rot + cam->angle);
	  	// put this inside a method, but do it the legit way
		// everything after this will change once I do it the legit way
		// so dont bother refactoring anything
		float step = 0.01;
		while (!env->map[(int)(env->y + step * cam->ry)][(int)(env->x + step * cam->rx)])
			step+=0.01;
		// this could bet put in a method as well
		int hitx = (int)(env->x + step * cam->rx);
		int hity = (int)(env->y + step * cam->ry);
		int side = hity != (int)(env->y + (step-0.01) * cam->ry) ? 0 : 1;
		cam->rx = cam->rx * step;
		cam->ry = cam->ry * step;
		float h = 0.5 * env->focal * env->h / get_ray_dist(cam);
		int ds = -h + env->h / 2 < 0 ? 0 : -h + env->h / 2;
		int de = h + env->h / 2 >= env->h ? env->h - 1 : h + env->h / 2;
		y = ds;
		while (y <= de)
		{
			int ytex = (int)((y + h - env->h / 2) / h * texwidth) / 2;
			float sidescale = side ? hity - (env->y + cam->ry) : hitx - (env->x + cam->rx);
			int xtex = (int)fabs(sidescale * texwidth);
			img[x + y * env->w] = tex[ytex][xtex] * 0x00101304 * env->map[hity][hitx];
			y++;
		}
		float delta = 1.0 / (1.0 * env->h - y); // number of pixels to draw
		//while (env->keys[XK_g] && y < env->h)
		while (y < env->h)
		{
			delta = env->h / (2.0 * y - env->h);
			step =  delta / get_ray_dist(cam) * env->focal;
			//printf("texwidth\n");
			//interpolate between hitx, hity and env->x env->y
			int ytex = (int)(fabs((env->y + step * cam->ry) - (int)(env->y + step * cam->ry)) * texwidth);
			int xtex = (int)(fabs((env->x + step * cam->rx) - (int)(env->x + step * cam->rx)) * texwidth);
			img[x + y *          env->w] = tex[ytex][xtex] * 0x13122002;
			img[x + (env->h-y) * env->w] = tex[ytex][xtex] * 0x04111024;
			y++;
		}
		x++;
	}
	draw_minimap(env, img, 5);
	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{

	t_env		*env;
	t_cam		*cam;

	env = malloc(sizeof(t_env));
	cam = malloc(sizeof(t_cam));
	env->cam = cam;
	parse_args(env, argc, argv);
	env->w = 500;
	env->h = 500;
	env->x = 5.0;
	env->y = 5.0;
	env->rot = 0.0;
	env->focal = 0.7;
	env->pt = getMicrotime();
	if (!(env->mlx = get_mlx()) || !(env->win = get_win(env->w, env->h, "wolf3d")))
		exit_error("get_win()");
	//clear_img(get_img(&env->img, env->w, env->h), env->w, env->h, 0x0000000);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, mouse_move_hook, env);
	mlx_hook(env->win, 2, 1L << 0, key_down_hook, env);
	mlx_key_hook(env->win, key_up_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	XWarpPointer(((t_xvar *)get_mlx())->display, None, ((t_win_list *)(((t_xvar *)get_mlx())->win_list))->window, 0, 0, 0, 0, env->w/2, 10);
	mlx_loop(get_mlx());
	if (env)
		free(env);
	exit(0);
}
