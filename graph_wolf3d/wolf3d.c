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


#define mapWidth 24
#define mapHeight 24
int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
float g = 0.0;
int		draw(void *p)
{
	t_env			*env;
	int				*img;
	int				i;
	int				j;
	int				x;
	int				y;

	g += 0.001;
	env = (t_env *)p;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0x00000000);

	// handle input
	if (env->keys['w'] || env->keys['s'])
	{
		env->x += 0.1 * cos(env->rot) * (env->keys['w'] ? 1 : -1);
		env->y += 0.1 * sin(env->rot) * (env->keys['w'] ? 1 : -1);
	}
	if (env->keys['a'])
		env->rot -= 0.08;
	if (env->keys['d'])
		env->rot += 0.08;
	if (env->keys['r']) env->focal -= 0.1;
	if (env->keys['f']) env->focal += 0.1;

	int yc = 5;
	int xc = 5;
	//sweep screen from left to right
	x = 0;
	while (x < env->w)
	{
		// DO IT VIA THE OTHER METHOD YOU IDIOT
		float sweep = (float)x / (float)env->w - 0.5;
		float angle = atan(sweep / env->focal);
		float ray = env->rot + angle;
		float rx = cos(ray);
	  	float ry = sin(ray);
	  	
	  	// that magic number is the field of view, in radians
	  	img[(int)((env->x + rx) * xc) +
			(int)((env->y + ry) * yc) * env->w] = 0x00ffff00;
		float step = 0.0;
		while (!env->map[(int)(env->y + step*ry)][(int)(env->x + step*rx)])
		{
			//img[(int)(xc*env->x + xc*step*rx) +
			//	(int)(yc*env->y + yc*step*ry) * env->w] = 0x00ffff00;
			step+=0.05;
		}
		int hitx = (int)(env->x + step*rx);
		int hity = (int)(env->y + step*ry);

		float dist = sqrt((env->y - step*ry) * (env->y - step*ry)
			+ (env->x - step*rx)*(env->x - step*rx)) * cos(angle);
		//float dist = (hitx = env->x + (1 - stepX) / 2) / rx;d
		int lineheight = (int)(env->h / dist);
		int drawstart = -lineheight + env->h / 2;
      	if(drawstart < 0)drawstart = 0;
      	int drawend = lineheight + env->h / 2;
      	if(drawend >= env->h)drawend = env->h - 1;

		y = drawstart;
		while (y < drawend)
		{
			img[x + y * env->w] = env->map[hity][hitx] * 0x99859347;
			y++;
		}
		x++;
	}



	// drawwalls
	i = -1;
	while (++i < env->maph)
	{
		j = -1;
		while (++j < env->mapw)
		{
			y = yc * i + 1;
			while (y < yc * i + yc - 1)
			{
				x = xc * j + 1;
				while (x < xc * j + xc - 1)
				{
					if (y < yc * i + 2 || y > yc * i + yc - 3
						|| x < xc * j + 2 || x > xc * j + xc - 3)
						if (env->map[i][j])
							img[x + y * env->w] = env->map[i][j] * 0x99859347;
					x++;
				}
				y++;
			}
		}
	}
	//draw player
	img[(int)(env->x*xc) +
		(int)(env->y*yc) * env->w] = 0x00ffff00;
	mlx_put_image_to_window(get_mlx(), env->win, env->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = malloc(sizeof(t_env));
	parse_args(env, argc, argv);
	env->w = 800;
	env->h = 800;
	env->x = 6.1;
	env->y = 6.1;
	env->rot = 0.0;
	env->focal = 0.8;
	if (!(env->mlx = get_mlx()))
		exit_error("get_mlx()");
	if (!(env->win = get_win(env->w, env->h, "wolf3d")))
		exit_error("get_win()");
	clear_img(get_img(&env->img, env->w, env->h), env->w, env->h, 0x00000000);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, 2, 1L << 0, key_down_hook, env);
	mlx_key_hook(env->win, key_up_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env) free(env);
	exit(0);
}
