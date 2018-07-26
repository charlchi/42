/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/20 13:37:36 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void		search_init(t_info *info, t_search *search)
{
	int			i;

	while (search->len >= 0)
	{
		search->len = -1;
		i = -1;
		while (++i < info->n)
		{
			search->path[i] = -1;
			search->dis[i] = 50000000;
		}
		search->dis[info->start] = 0;
		search_graph(search, info, 0, info->start);
	}
}

t_search	*get_sol(t_info *info)
{
	t_search	*minsol;
	t_search	*ps;
	t_list		*path;

	path = info->paths;
	minsol = (t_search *)path->content;
	while (path)
	{
		ps = (t_search *)path->content;
		if (ps->len < minsol->len)
			minsol = ps;
		path = path->next;
	}
	return (minsol);
}

void		print_ants(t_info *info, t_search *sol)
{
	char	**moves;
	char	*antname;
	int		i;
	int		j;

	moves = (char **)malloc(sizeof(char *) * (info->ants + sol->len - 1));
	i = 0;
	while (i < info->ants + sol->len - 1)
		moves[i++] = ft_strnew(0);
	i = -1;
	while (++i < info->ants)
	{
		j = -1;
		while (++j < sol->len)
		{
			antname = get_ant_name(i + 1, info->name[sol->path[j + 1]]);
			moves[i + j] = ft_strjoin(moves[i + j], antname);
		}
	}
	i = 0;
	while (i < info->ants + sol->len - 1)
		ft_putendl(moves[i++]);
	free(moves);
}

void		search_graph(t_search *s, t_info *info, int d, int n)
{
	int			i;

	s->path[d] = n;
	if (n == info->end)
	{
		found_solution(s, info, d);
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

void		found_solution(t_search *s, t_info *info, int d)
{
	int			i;
	t_search	*sol;
	t_list		*elem;

	sol = (t_search *)malloc(sizeof(t_search));
	sol->path = (int *)malloc(sizeof(int) * (d + 1));
	ft_memcpy(sol->path, s->path, sizeof(int) * (d + 1));
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
		info->graph[s->path[i]][s->path[i - 1]] = 0;
		info->graph[s->path[i - 1]][s->path[i]] = 0;
	}
}
