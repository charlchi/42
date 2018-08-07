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

#include "fdf.h"

float	vec3distlp(t_vec3 *o, t_vec3 *d, t_vec3 *p)
{
	t_vec3 crossp;
	t_vec3 op;

	op = vec3sub(o, p);
	crossp = vec3cross(&op, d);
	return (vec3len(&crossp) / vec3len(d));
}
