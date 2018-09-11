/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 12:56:16 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <GL/gl.h>
# include <GL/glut.h>
# include <GL/glu.h>
# include "libft/libft.h"
# include "vec3.h"
# include "geometry.h"

typedef struct	s_hit
{
	float	d;
	t_vec3	u;
	t_vec3	n;
	t_shape	*shape;
	int		hit;
}				t_hit;

typedef struct	s_cam
{
	t_vec3	*ro;
	t_vec3	*rd;
	t_vec3	*la;
	t_vec3	*c;
	t_vec3	*u;
	t_vec3	*r;
	t_vec3	*f;
}				t_cam;

typedef struct	s_env
{	
	t_cam		*cam;
	t_shape		*scene;
	int			nshapes;
	int			keys[80000];
	int			w;
	int			h;
	int			wd;
	long		pt;
	float		dt;
	int			*imgdata;
}				t_env;

t_env			*g_env;

void			init_cam(void);
void			init_scene(void);
void			keysdown(unsigned char key, int x, int y);
void			keysup(unsigned char key, int x, int y);
void			mouse(int button, int state, int x, int y);
void			handle_input(void);
void			draw_loop(void);
long			get_micro_time(void);
float			rando(void);
int				draw(void);
void			update_cam(t_cam *cam);
void			set_raydir(float x, float y, t_cam *cam);

#endif
