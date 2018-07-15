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

int gsol = 0;

int			main(void)
{
	t_info		info;
	char		*l;
	int			*path;
	int			*mdis;

	read_nants(&info, &l);
	read_rooms(&info, &l);
	read_links(&info, &l);
	if (!(path = (int *)malloc(sizeof(int) * info.n)))
		exit_error();
	if (!(mdis = (int *)malloc(sizeof(int) * info.n)))
		exit_error();

	gsol = 1;
	while (gsol > 0)
	{
		gsol = 0;
		int i = 0;
		while (i < info.n)
		{
			path[i] = -1;
			mdis[i++] = 50000000;
		}
		mdis[info.start] = 0;
		search_graph(path, mdis, 0, &info, info.start);
		printf("Solutions found : %d\n", gsol);
	}


	free(path);
	return (0);
}

void		search_graph(int *path, int *mdis, int d, t_info *info, int n)
{
	int		i;

	path[d] = n;
	if (n == info->end)
	{
		gsol++;
		i = 1;
		while (i <= d)
		{
			info->graph[path[i]][path[i-1]] = 0;
			info->graph[path[i-1]][path[i]] = 0;
			i++;
		}
	}
	else if (d < info->n)
	{
		i = -1;
		while (++i < info->n)
			if (connected(info, i, n))
				if (d < mdis[i])
					mdis[i] = d + 1;
		i = -1;
		while (++i < info->n)
			if (connected(info, i, n) && d < mdis[i])
				search_graph(path, mdis, d + 1, info, i);
		
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
