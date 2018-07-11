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
	int i = 0;
	while (i < info.n)
		mdis[i++] = 20000000;
	printf("______________________Searching graph_____________________\n");
	search_graph(path, mdis, 0, &info, info.end);
	printf("______________________Done________________________________\n");
	printf("Solutions found : %d\n", gsol);
	free(path);
	return (0);
}

void		search_graph(int *path, int *mdis, int d, t_info *info, int n)
{
	int		i;


	
	// path is the path this cycle has taken
	// d is the length along that path
	// mdis stores the minimum length we've found to this node

	// check whether this node has been encoutnered in this loop
	i = 0;
	while (i < d)
		if (path[i++] == n)
			return ;
	path[d] = n;
	mdis[n] = d;

	if (mdis[n] < d)
		return;

	//if (mdis[n] >= d)

	if (n == info->start)
	{
		gsol++;
		//printf(".");
		//fflush(0);
		
		//i = 0;
		//printf("[");
		//while (i < d)
		//	printf("%s-", info->name[path[i++]]);
		//printf("%s] : len %d\n", info->name[path[d]], d);
	}
	else if (d < info->n)
	{
		
		i = 0;
		while (i < info->n)
		{
			//if (i != n && info->graph[n][i] == 1 && mdis[n] >= mdis[i])
			if (connencted(info, i, n)
				&& (mdis[n] == 0 || d <= mdis[i]))
				search_graph(path, mdis, d + 1, info, i);
			i++;
		}
	}
}

int			connencted(t_info *info, int i, int n)
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
