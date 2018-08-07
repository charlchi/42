/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:54:56 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 17:03:52 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	vec3new(float x, float y, float z)
{
	t_vec3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

void	vec3rot(t_vec3 *r, float xr, float yr, float zr)
{
	float		x;
	float		y;
	float		z;

	x = r->x;
	y = r->y;
	z = r->z;
	r->x = (cos(xr) * cos(yr)) * x +
		(cos(xr) * sin(yr) * sin(zr) - sin(xr) * cos(zr)) * y +
		(cos(xr) * sin(yr) * cos(zr) + sin(xr) * sin(zr)) * z;
	r->y = (sin(xr) * cos(yr)) * x +
		(sin(xr) * sin(yr) * sin(zr) + cos(xr) * cos(zr)) * y +
		(sin(xr) * sin(yr) * cos(zr) - cos(xr) * sin(zr)) * z;
	r->z = (-sin(yr)) * x +
		(cos(yr) * sin(zr)) * y +
		(cos(yr) * cos(zr)) * z;
}

void	vec3scale(t_vec3 *n, float mag)
{
	n->x = n->x * mag;
	n->y = n->y * mag;
	n->z = n->z * mag;
}

void	vec3norm(t_vec3 *n)
{
	float len;

	len = vec3len(n);
	n->x = n->x / len;
	n->y = n->y / len;
	n->z = n->z / len;
}

t_vec3	vec3cross(t_vec3 *u, t_vec3 *v)
{
	t_vec3 ret;

	ret.x = (u->y * v->z) - (u->z * v->y);
	ret.y = (u->z * v->x) - (u->x * v->z);
	ret.z = (u->x * v->y) - (u->y * v->x);
	return (ret);
}
