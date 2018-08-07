/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:23:10 by cmoller           #+#    #+#             */
/*   Updated: 2018/05/21 13:34:19 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char const *src)
{
	int		i;

	i = 0;
	while ((dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}