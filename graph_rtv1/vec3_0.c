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

#include "rtv1.h"

t_vec3	*vec3set(t_vec3 *out, float x, float y, float z)
{
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vec3	*vec3new(float x, float y, float z)
{
	t_vec3	*out;

	out = (t_vec3 *)malloc(sizeof(t_vec3));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vec3	*vec3scale(t_vec3 *in, t_vec3 *out, float mag)
{
	out->x = in->x * mag;
	out->y = in->y * mag;
	out->z = in->z * mag;
	return (out);
}

t_vec3	*vec3norm(t_vec3 *in, t_vec3 *out)
{
	float len;

	len = vec3len(in);
	out->x = in->x / len;
	out->y = in->y / len; 
	out->z = in->z / len;
}

t_vec3	*vec3cross(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	out->x = (a->y * b->z) - (a->z * b->y);
	out->y = (a->z * b->x) - (a->x * b->z);
	out->z = (a->x * b->y) - (a->y * b->x);
	return (out);
}
