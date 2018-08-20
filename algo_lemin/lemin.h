/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:09:49 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/17 11:53:50 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct	s_info
{
	int		ants;
	char	name[1100][100];
	int		n;
	int		start;
	int		end;
	int		x[1100];
	int		y[1100];
	int		graph[1100][1100];
	t_list	*paths;

}				t_info;

typedef struct	s_search
{
	int		*path;
	int		*dis;
	int		len;
}				t_search;

void			read_nants(t_info *info, char **l);
void			read_rooms(t_info *info, char **l);
int				read_comment(t_info *info, char **str);
void			read_room_add(t_info *info, char **str);
void			read_links(t_info *info, char **l);
int				get_room_index(t_info *info, char *name);
void			add_links(t_info *info, char **l);
void			search_graph(t_search *s, t_info *info, int d, int n);
void			search_init(t_info *info, t_search *search);
t_search		*get_sol(t_info *info);
void			print_ants(t_info *info, t_search *sol);
void			found_solution(t_search *s, t_info *info, int d);
char			*get_ant_name(int i1, char *name);
int				connected(t_info *info, int i, int n);

#endif
