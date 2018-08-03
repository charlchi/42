/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/31 11:39:56 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//http://man7.org/linux/man-pages/man2/gettimeofday.2.html
# include <sys/time.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"

typedef struct	s_cam 
{
	float	sweep;
	float	angle;
	float	rx;
	float	ry;
	float	step;
	int		hitx;
	int		hity;
	int		side;
	int		ds;
	int		de;
	float	h;
}				t_cam;

typedef struct	s_env
{
	int		**map;
	int		mapw;
	int		maph;
	int		keys[80000];
	int		w;
	int		h;
	float	x;
	float	y;
	float	rot;
	float	focal;
	t_cam	*cam;
	void	*mlx;
	void	*win;
	void	*img;
	long	pt;
	float	dt;
}				t_env;

long		getMicrotime(void);
void		parse_args(t_env *env, int argc, char **argv);
void		parse(t_list *argvlst, t_env *env);
int			draw_loop(void *p);
void		handle_input(t_env *env);
int			key_up_hook(int key, void *p);
int			key_down_hook(int key, void *p);
int			mouse_hook(int button, int x, int y, void *p);
int			mouse_move_hook(int x, int y, void *p);
int			draw(void *p);
void		clear_img(int *img, int w, int h, int c);
int			*get_img(void **img, int w, int h);
void		*get_win(int w, int h, char *title);
void		*get_mlx(void);
float		get_ray_dist(t_cam *cam);
void		draw_minimap(t_env * env, int *img, int ppc);

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
