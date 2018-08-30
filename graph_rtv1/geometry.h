/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 12:56:16 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rtv1.h"

/* shape has an ID type, and then arbitrary property fields 
 * circle - c:center f1:radius
 * plane  - c:center vec1:normal f1:halfwidth
 */
typedef struct	s_shape
{
	int		type;
	t_vec3	c;
	t_vec3	vec1;
	t_vec3	vec2;
	float	f1;
	float	f2;
	float	f3;
}				t_shape;

#endif
