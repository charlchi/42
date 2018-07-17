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

float g = 0.0;
void	*get_mlx(void)
{
	static void		*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}

int		draw(void *p)
{
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
	int j;
	int i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			dword[j + i * env->width] += env->map[i][j] * 0x50ff4023;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(get_mlx(), env->win, env->img,0,0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		*env;


	env = malloc(sizeof(t_env));
	parse_args(env, argc, argv);
	if (!(env->mlx = get_mlx()))
		exit(0);
	if (!(env->win = mlx_new_window(get_mlx(), env->width, env->height, "FDF")))
		exit(0);
	if (!(env->img = mlx_new_image(get_mlx(), env->width, env->height)))
		exit(0);
	mlx_mouse_hook(env->win, mouse_hook, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, draw_loop, env);
	mlx_loop(env->mlx);
	if (env) free(env);
	exit(0);
}
