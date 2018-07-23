/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
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
	info.paths = NULL;
	search.len = 0;
	while (search.len >= 0)
	{
		search.len = -1;
		i = -1;
		while (++i < info.n)
		{
			search.path[i] = -1;
			search.dis[i] = 50000000;
		}
		search.dis[info.start] = 0;
		search_graph(&search, &info, 0, info.start);
		if (search.len >= 0)
			printf("Solutions found : len %d\n", search.len);
	}
	i = 0;
	int j;
	t_list *path;
	t_search *ps;
	path = info.paths;
	while (path)
	{
		ps = (t_search *)path->content;
		j = 0;
		while (j < ps->len)
		{
			printf("%d ", ps->path[j]);
			j++;
		}
		printf("\n");
		path = path->next;
		i++;
	}
	printf("%d\n", i);
	free(search.path);
	free(search.dis);
	return (0);
}

void		search_graph(t_search *s, t_info *info, int d, int n)
{
	int			i;
	t_search	*sol;
	t_list		*elem;

	s->path[d] = n;
	if (n == info->end)
	{
		sol = (t_search *)malloc(sizeof(t_search));
		sol->path = (int *)malloc(sizeof(int) * d);
		ft_memcpy(sol->path, s->path, sizeof(int) * d);
		sol->dis = (int *)malloc(sizeof(int) * d);
		ft_memcpy(sol->dis, s->dis, sizeof(int) * d);
		sol->len = d;
		s->len = d;
		elem = (t_list *)malloc(sizeof(t_list));
		elem->content = sol;
		ft_lstappend(&info->paths, elem);
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