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
	ft_putchar('\n');
}

void	add_links(t_info *info, char **l)
{
	char	**str;
	int		i;
	int		j;

	str = ft_strsplit(*l, '-');
	if (ft_strstrlen(str) != 2)
		exit_error("");
	i = get_room_index(info, str[0]);
	j = get_room_index(info, str[1]);
	ft_putendl(*l);
	info->graph[i][j] = 1;
	info->graph[j][i] = 1;
}

int		get_room_index(t_info *info, char *name)
{
	int		i;

	i = 0;
	while (i < info->n)
	{
		if (ft_strcmp(info->name[i], name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
