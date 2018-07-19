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
#include "mlx.h"
#include "../libft/libft.h"

typedef struct	s_env
{
	int		**map;
	int		mapw;
	int		maph;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgdata;
	float	x;
	float	y;
	float	z;
	float	scale;
	float	rot;
}				t_env;

void		parse_args(t_env *env, int argc, char **argv);
int			draw_loop(void *p);
int			key_hook(int key, void *p);
int			mouse_hook(int button, int x, int y, void *p);
int			draw(void *p);

typedef struct	s_vec3
{
	float x;
	float y;
	float z;
}				t_vec3;

int			mainImage(int x, int y, t_env *env);
t_vec3	vec3new(float x, float y, float z);
void	vec3scale(t_vec3 *n, float mag);
void	vec3norm(t_vec3 *n);
t_vec3	vec3cross(t_vec3 *u, t_vec3 *v);
float	vec3dot(t_vec3 *u, t_vec3 *v);
float	vec3angle(t_vec3 *u, t_vec3 *v);
t_vec3	vec3add(t_vec3 *f, t_vec3 *s);
t_vec3	vec3sub(t_vec3 *f, t_vec3 *s);
float	vec3len(t_vec3 *p);
float	vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p);

#endif