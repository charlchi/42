/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:18:22 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float g = 0.0;
int		main_image(int x, int y, t_env *env)
{
	// define camera position and 
	// and the point it's facing
	// get eye pos, just vecc3norm(vec3sub(cam, point)) 
	float uvx = (float)x / (float)env->w;
	uvx *= (float)env->w/(float)env->h;
	float uvy = (float)y / (float)env->h;
	t_vec3 ro = vec3new(0.0, 0.0, -5.0);
	t_vec3 rd = vec3new(
		uvx - 0.5 - ro.x,
		uvy - 0.5 - ro.y,
		0.0 - ro.z
	);
	t_vec3 p;
	float mindis = 100000.0;
	p.x = 0.2 * cos(2.0 * g);
	p.y = 0.2 * sin(3.0 * g);
	p.z = -17.0 + 10.0 * sin(2.8 + g);
	mindis = vec3distlp(&ro, &rd, &p);
	return (mindis < 0.1 ? 0x0000ff00 + (255 * (mindis * 10.0)) : 0x00000000);
}

int		draw(void *p)
{
	t_env			*env;
	int				*img;
	int				x;
	int				y;

	g += 0.1;
	env = (t_env *)p;
	img = get_img(&env->img, env->w, env->h);
	clear_img(img, env->w, env->h, 0x00000000);
	y = 0;
	while (y < env->h)
	{
		x = 0;
		while (x < env->w)
		{
			img[x + y * env->w] = main_image(x, y, env);
			//img[x + y * env->w] = ((int)(g*g + y) & (int)(g*g + x));
			x++;
		}
		y++;
	}
	return (0);
}

int		main(void)
{
	t_env		*env;

	env = malloc(sizeof(t_env));
	env->w = 400;
	env->h = 400;
	env->img = NULL;
	env->pt = get_micro_time();
	if (!(env->mlx = get_mlx()))
		exit_error("get_mlx()");
	if (!(env->win = get_win(env->w, env->h, "rtv1")))
		exit_error("get_win()");
	mlx_hook(env->win, 2, 1L << 0, key_down_hook, env);
	mlx_key_hook(env->win, key_up_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
	mlx_loop(get_mlx());
	if (env)
		free(env);
	exit(0);
}
