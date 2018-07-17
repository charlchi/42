/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:00 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

typedef struct	s_env
{
	t_list	*argvlst;
	int		**map;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgdata;
}				t_env;

void	parse_args(t_env *env, int argc, char **argv);
int		draw_loop(void *p);
int		key_hook(int key, void *p);
int		mouse_hook(int button, int x, int y, void *p);
int		draw(void *p);

#endif