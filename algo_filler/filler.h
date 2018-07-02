/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:41:35 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 10:22:40 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct	s_piece
{
	int			w; // width of piece
	int			h; // height
	int			n; // n is thye amount of stars
	int			x[100000]; // position of the star x
	int			y[100000]; // y
}				t_piece;

typedef struct	s_filler
{
	int			r;
	int			n;
	int			lc;
	int			uc;
	int			elc;
	int			euc;
	int			h;
	int			w;
	char		**m;
}				t_filler;

struct position {
	int x;
	int y;
}

typedef struct	String
{
	int			len;
	char		*buf;
	int			x[100000];
}				t_opieces;

int				init_game(t_filler *f);
void			read_map(t_filler *f);
void			read_piece(t_piece *p);
void			scan_ints(char **l, int *h, int *w);
void			get_opieces(t_filler *f, t_piece *p,
				t_opieces *op, t_opieces *eop);
void			add_opiece(t_filler *f, t_piece *p, t_opieces *op,
				int i[2]);
void			get_epieces(t_filler *f, t_opieces *eop);
int				get_epiece_edges(t_filler *f, int i, int j);
int				rank_overlap(t_filler *f, t_opieces *op, t_piece *p);
void			rank_dist(t_filler *f, t_opieces *op,
				t_opieces *eop, t_piece *p);
void			free_filler(char *l, t_filler *f);
double			sqrtaprox(double yd, double xd);

#endif
