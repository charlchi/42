/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 17:04:30 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p)
{
	t_vec3 crossp;

	vec3sub(o, p, o);
	vec3cross(&crossp, o, d);
	return (vec3len(&crossp) / vec3len(d));
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

t_vec3	*vec3fadd(t_vec3 *in, t_vec3 *out, float x, float y, float z)
{
	out->x = in->x + x;
	out->y = in->y + y;
	out->z = in->z + z;
	return (out);
}

t_vec3	*vec3cpy(t_vec3 *in, t_vec3 *out)
{
	out->x = in->x;
	out->y = in->y;
	out->z = in->z;
	return (out);
}