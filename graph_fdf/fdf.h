/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:47:35 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 17:26:11 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_env
{
	int			**map;
	int			mapw;
	int			maph;
	int			w;
	int			h;
	void		*mlx;
	void		*win;
	void		*img;
	float		x;
	float		y;
	float		z;
	float		scale;
	float		rotx;
	float		roty;
	float		rotz;
	int			color;
	t_vec3		*points;
}				t_env;

void			parse_args(int argc, char **argv, t_env *env);
void			parse(t_list *argvlst, t_env *env);
void			init_env(t_env *env);
int				draw_loop(void *p);
int				key_hook(int key, void *p);
int				mouse_hook(int button, int x, int y, void *p);
int				draw(void *p);
void			clear_img(int *img, int w, int h, int c);
void			exit_error(char *s);
void			clear_img(int *img, int w, int h, int c);
int				*get_img(void **img, int w, int h);
void			*get_win(int w, int h, char *title);
void			*get_mlx(void);
void			get_points(t_env *env);
void			draw_points(t_env *env);
void			draw_line(t_vec3 p1, t_vec3 p2, t_env *env);
void			vec3scale(t_vec3 *n, float mag);
void			vec3norm(t_vec3 *n);
void			vec3rot(t_vec3 *r, float xr, float yr, float zr);
t_vec3			vec3new(float x, float y, float z);
t_vec3			vec3cross(t_vec3 *u, t_vec3 *v);
t_vec3			vec3add(t_vec3 *f, t_vec3 *s);
t_vec3			vec3sub(t_vec3 *f, t_vec3 *s);
float			vec3dot(t_vec3 *u, t_vec3 *v);
float			vec3angle(t_vec3 *u, t_vec3 *v);
float			vec3len(t_vec3 *p);
float			vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p);

#endif
