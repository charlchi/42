/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_readinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:39:29 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 15:14:45 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lemin.h"

void	read_nants(t_info *info, char **l)
{
	int			i;

	get_next_line(0, l);
	i = 0;
	while ((*l)[i] != '\0')
		if (!ft_isdigit((*l)[i++]))
			exit_error("");
	if (!ft_isdigit((*l)[0]) || (info->ants = ft_atoi(*l)) == 0)
		exit_error("");
	ft_putnbr(info->ants);
	ft_putchar('\n');
}

void	read_rooms(t_info *info, char **l)
{
	char	**str;
	int		ret;

	info->n = 0;
	info->start = -1;
	info->end = -1;
	while ((get_next_line(0, l)) > 0)
	{
		str = ft_strsplit(*l, ' ');
		ret = ft_strstrlen(str);
		if (ret == 1)
		{
			if (!read_comment(info, str))
				break ;
		}
		else if (ret == 3)
			read_room_add(info, str);
		else
			break ;
	}
	if (info->n == 0 || info->start == -1 || info->end == -1)
		exit_error("");
}

int		read_comment(t_info *info, char **str)
{
	if (str[0][0] != '#' || str[0][0] == 'L')
		return (0);
	if (ft_strcmp(str[0], "##start") == 0)
	{
		if (info->start != -1)
			exit_error("");
		info->start = info->n;
		ft_putendl("##start");
	}
	if (ft_strcmp(str[0], "##end") == 0)
	{
		if (info->end != -1)
			exit_error("");
		info->end = info->n;
		ft_putendl("##end");
	}
	return (1);
}

void	read_room_add(t_info *info, char **str)
{
	ft_strcpy(info->name[info->n], str[0]);
	info->x[info->n] = ft_atoi(str[1]);
	info->y[info->n] = ft_atoi(str[2]);
	ft_putstr(str[0]);
	ft_putchar(' ');
	ft_putstr(str[1]);
	ft_putchar(' ');
	ft_putendl(str[2]);
	info->n++;
}
