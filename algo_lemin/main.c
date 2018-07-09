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
	printf("Hello, World!\n");
	t_info		info;
	char		*l;
	int			*b;
	int			*dis;

	read_nants(&info, &l);
	printf("ants %d\n", info.ants);
	printf("current value of the line[%s]\n", l);
	read_rooms(&info, &l);
	read_links(&info, &l);
	if (!(b = (int *)malloc(sizeof(int) * info.n)))
		exit_error();
	if (!(dis = (int *)malloc(sizeof(int) * info.n)))
		exit_error();
	int i = 0;
	while (i < info.n)
		dis[i++] = 0;
	printf("search graph\n");
	search_graph(b, dis, info.n, &info, info.start);
	free(b);
	return (0);
}

void		search_graph(int *b, int *dis, int d, t_info *info, int n)
{
	int		i;

	i = 0;
	while (i < info->n - d)
		if (b[i++] == n)
		{
			/*i = 1;
			while (i <= info->n - d)
				printf("-%s-", info->name[b[i++]]);*/
			printf(" . ");
			return ;
		}
	b[info->n - d] = n;
	dis[n] = info->n - d;
	if (n == info->end)
	{
		i = 1;
		printf("\n");
		while (i < info->n - d)
			printf("-%s-", info->name[b[i++]]);
		printf("END : length %d\n", i);
	}
	//else if (d > 0 && dis[n] < d)
	else if (d > 0 && dis[n] < d - 1)
	{
		i = 0;
		while (i < info->n)
		{
			if (i != n && info->graph[n][i] == 1 && dis[i] <= d - 1)
				search_graph(b, dis, d - 1, info, i);
			i++;
		}
	}
}

void		exit_error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

