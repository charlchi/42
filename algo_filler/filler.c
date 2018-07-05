/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:21:43 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 09:54:02 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_piece			p;
	t_filler		f;
	t_opieces		op;
	t_opieces		eop;
	char			*l;

	if (!init_game(&f))
		return (-1);
	f.r = 1;
	while (f.r > 0)
	{
		read_map(&f);
		read_piece(&p);
		get_opieces(&f, &p, &op, &eop);
		if (!(rank_overlap(&f, &op, &p)))
			rank_dist(&f, &op, &eop, &p);
		ft_putnbr(op.y[op.n]);
		ft_putchar(' ');
		ft_putnbr(op.x[op.n]);
		ft_putchar('\n');
		f.r = get_next_line(0, &l);
	}
	free_filler(l, &f);
	return (0);
}

void		get_opieces(t_filler *f, t_piece *p, t_opieces *op, t_opieces *eop)
{
	int		i;
	int		j;
	int		arr[2];

	op->n = 0;
	i = 0;
	while (i < f->h - p->h + 1)
	{
		j = 0;
		while (j < f->w - p->w + 1)
		{
			n_overlaps = 0;
			blocks = 0;
			n = 0;
			while (n < p->n)
			{
				// count overlaps with stars
				if (f->m[y + p->y[n]][y + p->x[n]] == f->lc // lowercase
						|| f->m[y + p->y[n]][y + p->x[n]] == f->uc) //uppercase
					no++;
				// count overlaps with enemies blocks
				if (f->m[y + p->y[n]][y + p->x[n]] == f->elc // enemy lc
						|| f->m[y + p->y[n]][y + p->x[n]] == f->euc) // enemy up
					blocks++;
				n++;
				if (no == 1 && blocks == 0) // if overlap with stars == 1 and no blockage
				{
					op->y[op->n] = x;
					op->x[op->n] = y;
					op->n++;
				}
				i++;
			}
		}
	}
}

o_piece {
	int n;
	int x[1000];
	int y[1000];
}


op->n = 0;
x [4] []
y [5] []

op->n ++;  == 1

x [4] [10]
y [5] [11]

n == 2

x [4] [10] [20]
y [5] [11] [9]
























if (no == 1 && blocks == 0)
{
	op->y[op->n] = i[0];
	op->x[op->n] = i[1];
	op->n++;
	arr[0] = i;
	arr[1] = j;
	add_opiece(f, p, op, arr);
	j++;
}
i++;
}
get_epieces(f, eop);
}

void		add_opiece(t_filler *f, t_piece *p, t_opieces *op, int i[2])
{
	int		no;
	int		blocks;
	int		n;

	no = 0;
	blocks = 0;
	n = 0;
	while (n < p->n)
	{
		if (f->m[y + p->y[n]][y + p->x[n]] == f->lc
				|| f->m[y + p->y[n]][y + p->x[n]] == f->uc)
			no++;
		if (f->m[y + p->y[n]][y + p->x[n]] == f->elc
				|| f->m[y + p->y[n]][y + p->x[n]] == f->euc)
			blocks++;
		n++;
	}
	if (no == 1 && blocks == 0)
	{
		op->y[op->n] = i[0];
		op->x[op->n] = i[1];
		op->n++;
	}
}

void		get_epieces(t_filler *f, t_opieces *eop)
{
	int		i;
	int		j;

	eop->n = 0;
	i = 1;
	while (i < f->h - 1)
	{
		j = 1;
		while (j < f->w - 1)
		{
			if (f->m[i][j] == '.' && get_epiece_edges(f, i, j))
			{
				f->m[i][j] = '*';
				eop->y[eop->n] = i;
				eop->x[eop->n++] = j;
			}
			j++;
		}
		i++;
	}
}

int			get_epiece_edges(t_filler *f, int i, int j)
{
	return ((f->m[i - 1][j - 1] == f->elc || f->m[i - 1][j - 1] == f->euc
				|| f->m[i - 1][j + 0] == f->elc || f->m[i - 1][j + 0] == f->euc
				|| f->m[i - 1][j + 1] == f->elc || f->m[i - 1][j + 1] == f->euc
				|| f->m[i + 0][j - 1] == f->elc || f->m[i + 0][j - 1] == f->euc
				|| f->m[i + 0][j + 1] == f->elc || f->m[i + 0][j + 1] == f->euc
				|| f->m[i + 1][j - 1] == f->elc || f->m[i + 1][j - 1] == f->euc
				|| f->m[i + 1][j + 0] == f->elc || f->m[i + 1][j + 0] == f->euc
				|| f->m[i + 1][j + 1] == f->elc || f->m[i + 1][j + 1] == f->euc));
}
