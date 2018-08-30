/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 12:56:16 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

t_vec3	*vec3set(t_vec3 *out, float x, float y, float z);
t_vec3	*vec3fadd(t_vec3 *in, t_vec3 *out, float x, float y, float z);
t_vec3	*vec3cpy(t_vec3 *in, t_vec3 *out);
t_vec3	*vec3new(float x, float y, float z);
t_vec3	*vec3scale(t_vec3 *in, t_vec3 *out, float mag);
t_vec3	*vec3norm(t_vec3 *in, t_vec3 *out);
t_vec3	*vec3cross(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3	*vec3add(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3	*vec3sub(t_vec3 *a, t_vec3 *b, t_vec3 *out);
float	vec3dot(t_vec3 *u, t_vec3 *v);
float	vec3angle(t_vec3 *u, t_vec3 *v);
float	vec3len(t_vec3 *p);
float	vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p);
void	vec3rot(t_vec3 *r, float xr, float yr, float zr);

#endif
