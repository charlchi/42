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

#include "rtv1.h"

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

void		load_images(t_env *env, char *walls, char *ceil)
{
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
}
