/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*get_ant_name(int i1, char *name)
{
	char	*ret;
	char	*istr;

	istr = ft_itoa(i1);
	ret = ft_strnew(2 + ft_strlen(istr) + ft_strlen(name));
	ft_strcat(ret, "L");
	ft_strcat(ret, istr);
	ft_strcat(ret, "-");
	ft_strcat(ret, name);
	ft_strcat(ret, " ");
	return (ret);
}

int			connected(t_info *info, int i, int n)
{
	if (i == n || info->graph[n][i] == 0)
		return (0);
	return (1);
}
