/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:41:35 by cmoller           #+#    #+#             */
/*   Updated: 2018/06/25 09:34:06 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_game(t_filler *f)
{
	int		i;
	char	*l;

	get_next_line(0, &l);
	f->n = l[10] - '0';
	f->lc = 'o';
	f->uc = 'O';
	f->elc = 'x';
	f->euc = 'X';
	if (f->n == 2)
	{
		f->lc = 'x';
		f->uc = 'X';
		f->elc = 'o';
		f->euc = 'O';
	}
	get_next_line(0, &l);
	scan_ints(&l, &(f->h), &(f->w));
	if (!(f->m = (char **)malloc(f->h * sizeof(char *))))
		return (0);
	i = 0;
	while (i < f->h)
		if (!(f->m[i++] = (char*)malloc(f->w * sizeof(char))))
			return (0);
	return (1);
}

void	read_map(t_filler *f)
{
	int		i;
	int		j;
	char	*l;

	get_next_line(0, &l);
	i = 0;
	while (i < f->h)
	{
		get_next_line(0, &l);
		j = -1;
		while (++j < f->w)
			f->m[i][j] = l[j + 4];
		i++;
	}
}

void	read_piece(t_piece *p)
{
	int		i;
	int		j;
	char	*l;

	get_next_line(0, &l);
	scan_ints(&l, &(p->h), &(p->w));
	p->n = 0;
	i = 0;
	while (i < p->h)
	{
		get_next_line(0, &l);
		j = 0;
		while (j < p->w)
		{
			if (l[j] == '*')
			{
				p->y[p->n] = i;
				p->x[p->n] = j;
				p->n++;
			}
			j++;
		}
		i++;
	}
}
