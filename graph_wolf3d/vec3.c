/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:00 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec3	vec3new(float x, float y, float z)
{
	t_vec3 ret = {
		x,
		y,
		z
	};
	return (ret);
}

void	vec3rot(t_vec3 *r, float xr, float yr, float zr)
{
	t_vec3 xrot = {
		r->x,
		cos(xr) * r->y + -sin(xr) * r->z,
		sin(xr) * r->y + cos(xr) * r->z,
	};
	t_vec3 yrot = {
		cos(yr) * r->x + sin(yr) * r->z,
		r->y,
		-sin(yr) * r->x + cos(yr) * r->z,
	};
	t_vec3 zrot = {
		cos(zr) * r->x + -sin(zr) * r->y,
		sin(zr) * r->x + cos(zr) * r->y,
		r->z,
	};
	r->x = xrot.x + yrot.x + zrot.x;
	r->y = xrot.y + yrot.y + zrot.y;
	r->z = xrot.z + yrot.z + zrot.z;
}

void	vec3scale(t_vec3 *n, float mag)
{
	n->x = n->x * mag;
	n->y = n->y * mag;
	n->z = n->z * mag;
}

void	vec3norm(t_vec3 *n)
{
	float len = vec3len(n);
	n->x = n->x / len;
	n->y = n->y / len;
	n->z = n->z / len;
}

t_vec3	vec3cross(t_vec3 *u, t_vec3 *v)
{
	t_vec3 ret = {
		(u->y * v->z) - (u->z * v->y),
		(u->z * v->x) - (u->x * v->z),
		(u->x * v->y) - (u->y * v->x)
	};
	return (ret);
}

float	vec3dot(t_vec3 *u, t_vec3 *v)
{
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

float	vec3angle(t_vec3 *u, t_vec3 *v)
{
	return acos(vec3dot(u, v) / (vec3len(u) * vec3len(v)));
}

t_vec3	vec3add(t_vec3 *f, t_vec3 *s)
{
	t_vec3 ret = {
		f->x + s->x,
		f->y + s->y ,
		f->z + s->z
	};
	return (ret);
}

t_vec3	vec3sub(t_vec3 *f, t_vec3 *s)
{
	t_vec3 ret = {
		f->x - s->x,
		f->y - s->y,
		f->z - s->z
	};
	return (ret);
}

float	vec3len(t_vec3 *p)
{
	return (sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z)));
}

float	vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p)
{
	t_vec3 crossp;
	t_vec3 op;

	op = vec3sub(o, p);
	crossp = vec3cross(&op, d);
	return vec3len( &crossp ) / vec3len(d);
}