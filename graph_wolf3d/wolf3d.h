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
#include <sys/time.h>
//http://man7.org/linux/man-pages/man2/gettimeofday.2.html
#include "mlx.h"
#include "../libft/libft.h"

typedef struct	s_env
{
	int		**map;
	int		mapw;
	int		maph;
	int		keys[20000];
	int		w;
	int		h;
	float	x;
	float	y;
	float	rot;
	float	focal;
	void	*mlx;
	void	*win;
	void	*img;
}				t_env;

void		parse_args(t_env *env, int argc, char **argv);
void		parse(t_list *argvlst, t_env *env);
int			draw_loop(void *p);
int			key_up_hook(int key, void *p);
int			key_down_hook(int key, void *p);
int			mouse_hook(int button, int x, int y, void *p);
int			draw(void *p);
void		clear_img(int *img, int w, int h, int c);

typedef struct	s_vec3
{
	float x;
	float y;
	float z;
}				t_vec3;

int			mainImage(int x, int y, t_env *env);
void		vec3scale(t_vec3 *n, float mag);
void		vec3norm(t_vec3 *n);
void		vec3rot(t_vec3 *r, float xr, float yr, float zr);
t_vec3		vec3new(float x, float y, float z);
t_vec3		vec3cross(t_vec3 *u, t_vec3 *v);
t_vec3		vec3add(t_vec3 *f, t_vec3 *s);
t_vec3		vec3sub(t_vec3 *f, t_vec3 *s);
float		vec3dot(t_vec3 *u, t_vec3 *v);
float		vec3angle(t_vec3 *u, t_vec3 *v);
float		vec3len(t_vec3 *p);
float		vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p);

#endif