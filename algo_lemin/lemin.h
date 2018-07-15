/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:09:49 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/02 12:22:16 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

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

}				t_info;

void			read_nants(t_info *info, char **l);
void			read_rooms(t_info *info, char **l);
void			read_room_add(t_info *info, char **str);
void			read_links(t_info *info, char **l);
int				get_room_index(t_info *info, char *name);
void			add_links(t_info *info, char **l);
void			search_graph(int *b, int *dis, int depth, t_info *info, int n);
int				connected(t_info *info, int i, int n);
void			exit_error(void);

#endif
