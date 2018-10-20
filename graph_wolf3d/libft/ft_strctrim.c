/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:53:23 by cmoller           #+#    #+#             */
/*   Updated: 2018/05/28 14:14:06 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strctrim(char const *s, char c)
{
	int					start;
	int					end;
	char				*res;

	start = 0;
	while (s[start] == c)
		start++;
	if (start == ft_strlen(s))
	{
		res = ft_strnew(1);
		return (res);
	}
	end = ft_strlen(s) - 1;
	while (s[end] == c)
		end--;
	end++;
	res = ft_strsub(s, start, end - start);
	if (res == NULL)
		return (NULL);
	res[end - start] = 0;
	return (res);
}
