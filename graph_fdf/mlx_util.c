/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:07 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*get_img(t_env *env)
{
	char 			*data;
	int				bpp;
	int				sl;
	int				endian;

	if (!env->img)
		if (!(env->img = mlx_new_image(get_mlx(), env->w, env->h)))
			exit(0);
	data = mlx_get_data_addr(env->img, &bpp, &sl, &endian);
	return ((int *)data);
}

void	clear_img(int *img, int w, int h, int c)
{
	int				y;
	int				x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			img[x + y * w] = c;
			x++;
		}
		y++;
	}
}

void	*get_win(int w, int h, char *title)
{
	void			*win;

	win = mlx_new_window(get_mlx(), w, h, title);
	return (win);
}