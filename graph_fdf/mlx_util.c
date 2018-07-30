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

int		*get_img(void **img, int w, int h)
{
	char			*data;
	int				bpp;
	int				sl;
	int				endian;

	if (!*img)
		*img = mlx_new_image(get_mlx(), w, h);
	data = mlx_get_data_addr(*img, &bpp, &sl, &endian);
	return ((int *)data);
}

void	*get_win(int w, int h, char *title)
{
	void			*win;

	win = mlx_new_window(get_mlx(), w, h, title);
	return (win);
}

void	*get_mlx(void)
{
	static void		*mlx;

	if (!mlx)
		if (!(mlx = mlx_init()))
			exit_error("mlx_init()");
	return (mlx);
}
