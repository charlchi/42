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
	t_search	*sol;
	char		*l;

	read_nants(&info, &l);
	read_rooms(&info, &l);
	read_links(&info, &l);
	search.path = (int *)malloc(sizeof(int) * info.n);
	search.dis = (int *)malloc(sizeof(int) * info.n);
	if (!search.path || !search.dis)
		exit_error("");
	info.paths = NULL;
	search.len = 0;
	search_init(&info, &search);
	if (info.paths != NULL)
	{
		sol = get_sol(&info);
		print_ants(&info, sol);
	}
	else
		exit_error("");
	free(search.path);
	free(search.dis);
	return (0);
}
