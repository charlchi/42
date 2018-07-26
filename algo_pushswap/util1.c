/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:49 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/09 09:12:18 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		has_larger(int mid, t_stack *a)
{
	int		i;

	i = 0;
	while (i <= a->top)
		if (a->table[i++] > mid)
			return (1);
	return (0);
}

int		has_smallereq(int mid, t_stack *a)
{
	int		i;

	i = 0;
	while (i <= a->top)
		if (a->table[i++] <= mid)
			return (1);
	return (0);
}

int		get_mid(t_stack *a, int n)
{
	int		i;
	int		*table;

	table = (int *)malloc(sizeof(int) * (n + 1));
	i = 0;
	while (i <= n)
	{
		table[i] = a->table[a->top - i];
		i++;
	}
	bubble_sort(table, n + 1);
	i = (table[(n + 1) / 2]);
	free(table);
	return (i);
}

void	bubble_sort(int *tab, int size)
{
	int		i;
	int		j;
	int		t;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	free_search(t_search *search)
{
	free(search->ops);
	free(search->a.table);
	free(search->b.table);
	free(search);
}
