/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:21:16 by mgerber           #+#    #+#             */
/*   Updated: 2018/09/12 15:10:28 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

char	*strip_asm(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	while ((new = ft_strchr(*str, '\t')))
		*new = ' ';
	while ((*str)[i] == ' ' && (*str)[i] != '\0')
		i++;
	while ((*str)[j] != '#' && (*str)[j] != '\0')
		j++;
	j--;
	while ((*str)[j] == ' ')
		j--;
	new = (char*)malloc(sizeof(char) * (j - i + 1));
	while (i <= j)
		new[k++] = (*str)[i++];
	new[k] = '\0';
	return (new);
}
