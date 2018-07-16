/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/04 08:55:51 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int			main(void)
{
	t_info		info;
	t_search	search;
	char		*l;
	int			i;

	read_nants(&info, &l);
	read_rooms(&info, &l);
	read_links(&info, &l);
	if (!(search.path = (int *)malloc(sizeof(int) * info.n)))
		exit_error();
	if (!(search.dis = (int *)malloc(sizeof(int) * info.n)))
		exit_error();
	search.len = 0;
	while (search.len >= 0)
	{
		search.len = -1;
		i = 0;
		while (i < info.n)
		{
			search.path[i] = -1;
			search.dis[i++] = 50000000;
		}
		search.dis[info.start] = 0;
		search_graph(&search, &info, 0, info.start);
		if (search.len >= 0)
			printf("Solutions found : len %d\n", search.len);
	}
	free(search.path);
	free(search.dis);
	return (0);
}

void		search_graph(t_search *s, t_info *info, int d, int n)
{
	int		i;

	s->path[d] = n;
	if (n == info->end)
	{
		s->len = d;
		i = 0;
		while (++i <= d)
		{
			info->graph[s->path[i]][s->path[i-1]] = 0;
			info->graph[s->path[i-1]][s->path[i]] = 0;
		}
	}
	else if (d < info->n)
	{
		i = -1;
		while (++i < info->n)
			if (connected(info, i, n))
				if (d < s->dis[i])
					s->dis[i] = d + 1;
		i = -1;
		while (++i < info->n)
			if (connected(info, i, n) && d < s->dis[i])
				search_graph(s, info, d + 1, i);
	}
}

int			connected(t_info *info, int i, int n)
{
	if (i == n || info->graph[n][i] == 0)
		return (0);
	return (1);
}

void		exit_error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}
