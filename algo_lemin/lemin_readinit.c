/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_readinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 12:51:47 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lemin.h"

void	read_nants(t_info *info, char **l)
{
	//int		i;

	get_next_line(0, l);
	if ((info->ants = ft_atoi(*l)) == 0)
		exit_error();
	// TODO FREE MALLOC
	/*
	if (!(info->x = (int *)malloc(sizeof(int) * info->ants)))
		exit_error();
	if (!(info->y = (int *)malloc(sizeof(int) * info->ants)))
		exit_error();
	if (!(info->graph = (int **)malloc(sizeof(int *) * info->ants)))
		exit_error();
	i = 0;
	while (i < info->ants)
		if (!(info->graph[i++] = (int *)malloc(sizeof(int) * info->ants)))
			exit_error();
	if (!(info->name = (char **)malloc(sizeof(char *) * info->ants)))
		exit_error();
	*/
}

void	read_rooms(t_info *info, char **l)
{
	char	**str;
	int		ret;

	printf("test %s \n", *l);
	info->n = 0;
	while ((get_next_line(0, l)) > 0)
	{
		printf("test %s \n", *l);
		str = ft_strsplit(*l, ' ');
		ret = ft_strstrlen(str);
		printf("managed to split [%s]\n", *l);
		if (ret == 1)
		{
			if (str[0][0] != '#' || str[0][0] == 'L')
				break ;
			if (ft_strcmp(str[0], "##start") == 0)
				info->start = info->n;
			if (ft_strcmp(str[0], "##end") == 0)
				info->end = info->n;
		}
		else if (ret == 3)
			read_room_add(info, str);
		else
			break ;
	}
}

void	read_room_add(t_info *info, char **str)
{
	//info->name[info->n] = ft_strdup(str[0]);
	ft_strcpy(info->name[info->n], str[0]);
	printf("adding room %s %s\n", info->name[info->n], str[0]);
	info->x[info->n] = ft_atoi(str[1]);
	info->y[info->n] = ft_atoi(str[2]);
	info->n++;
}
