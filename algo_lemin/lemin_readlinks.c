/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_readlinks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 13:01:33 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>


void	read_links(t_info *info, char **l)
{
	int		r;

	r = 1;
	while (r > 0)
	{
		if (ft_strlen(*l) > 0 && (*l)[0] != '#')
			add_links(info, l);
		r = get_next_line(0, l);
	}
}

void	add_links(t_info *info, char **l)
{
	char	**str;
	int		i;
	int		j;

	str = ft_strsplit(*l, '-');
	if (ft_strstrlen(str) != 2)
		exit_error();
	printf("get_room_index:    %s %s\n", str[0], str[1]);
	i = get_room_index(info, str[0]);
	j = get_room_index(info, str[1]);
	printf("got room_indeces   %d %d\n", i, j);
	printf("graph[i][j]   %d %d\n", i, j);
	printf("graph[j][i]   %d %d\n", j, i);
	info->graph[i][j] = 1;
	info->graph[j][i] = 1;
	printf("exiting add_links\n");
}

int     get_room_index(t_info *info, char *name)
{
	int     i;

	i = 0;
	while (i < info->n)
	{
		if (ft_strcmp(info->name[i], name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
