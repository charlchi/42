/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:22:01 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		get_ray_dist(t_cam *cam)
{
	float				x;
	float				y;

	x = cam->rx;
	y = cam->ry;
	return (sqrt(y * y + x * x * cos(cam->angle)));
}

long		get_micro_time(void)
{
	struct timeval		currenttime;

	gettimeofday(&currenttime, NULL);
	return (currenttime.tv_sec * (int)1e6 + currenttime.tv_usec);
}

void		handle_input(t_env *env)
{
	float				oldx;
	float				oldy;

	oldx = env->x;
	oldy = env->y;
	if (env->keys[XK_w] || env->keys[XK_s])
	{
		env->x += 0.004 * cos(env->rot) *
			env->dt * (env->keys[XK_s] ? -1 : 1);
		env->y += 0.004 * sin(env->rot) *
			env->dt * (env->keys[XK_s] ? -1 : 1);
	}
	if (env->keys[XK_d] || env->keys[XK_a])
	{
		env->x += 0.004 * cos(env->rot + 1.7) *
			env->dt * (env->keys[XK_a] ? -1 : 1);
		env->y += 0.004 * sin(env->rot + 1.7) *
			env->dt * (env->keys[XK_a] ? -1 : 1);
	}
	env->x = env->map[(int)oldy][(int)env->x] > 0 ? oldx : env->x;
	env->y = env->map[(int)env->y][(int)oldx] > 0 ? oldy : env->y;
	env->rot -= ((env->keys[XK_Left]) ? 0.004 : 0.0) * env->dt;
	env->rot += ((env->keys[XK_Right]) ? 0.004 : 0.0) * env->dt;
	env->focal -= env->keys[XK_r] ? 0.1 / env->dt : 0.0;
	env->focal += env->keys[XK_f] ? 0.1 / env->dt : 0.0;
}

void		load_images(t_env *env, char *walls, char *ceil)
{
	int					i;

	env->img = NULL;
	i = 0;
	while (i < 8000000)
		env->keys[i++] = 0;
	env->rot = 0;
	env->tex = (int **)malloc(640 * sizeof(int *));
	env->ftex = (int **)malloc(640 * sizeof(int *));
	load_image(walls, &env->tex);
	load_image(ceil, &env->ftex);
}

void		load_image(char *file, int ***tex)
{
	int		i;
	int		j;
	int		k;
	void	*img;
	int		*data;

	img = mlx_xpm_file_to_image(get_mlx(), file, &i, &j);
	data = (int *)(mlx_get_data_addr(img, &i, &j, &k));
	i = 0;
	while (i < 640)
	{
		(*tex)[i] = (int *)malloc(640 * sizeof(int));
		j = 0;
		while (j < 640)
		{
			(*tex)[i][j] = data[j + i * 640];
			j++;
		}
		i++;
	}
	free(data);
	free(img);
}
