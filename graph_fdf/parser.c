/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/17 16:45:00 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_args(t_env *env, int argc, char **argv)
{
	char 	**str;
	char	*l;

	get_next_line(0, &l);
	str = ft_strsplit(l, ' ');

	env->argvlst = ft_lstnew(str);
	env->width = ft_strstrlen(str);
	env->height = 1;
	while (get_next_line(0, &l))
	{
		str = ft_strsplit(l, ' ');
		ft_lstappend(env->argvlst, ft_lstnew(str));
		if (ft_strstrlen(str) != env->width)
			exit(0);
		env->height++;
	}
	printf("w:%d, h:%d\n", env->width, env->height);
	if (!(env->map = malloc(sizeof(int *) * env->height)))
		exit(0);
	int i = 0;
	while (i < env->height)
	{
		if (!(env->map[i] = malloc(sizeof(int) * env->width)))
			exit(0);
		i++;
	}

	t_list *current = env->argvlst;
	i = 0;
	int j;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			env->map[i][j] = ft_atoi(((char **)current->content)[j]);
			j++;
		}
		printf("\n");
		current = current->next;
		i++;
	}
}
