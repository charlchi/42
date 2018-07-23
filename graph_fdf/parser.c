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
	t_list	*argvlst;
	char 	**str;
	char	*l;

	get_next_line(0, &l);
	str = ft_strsplit(l, ' ');
	argvlst = ft_lstnew(str);
	env->mapw = ft_strstrlen(str);
	env->maph = 1;
	while (get_next_line(0, &l))
	{
		str = ft_strsplit(l, ' ');
		ft_lstappend(argvlst, ft_lstnew(str));
		if (ft_strstrlen(str) != env->mapw)
			exit(0);
		env->maph++;
		free(l);
	}
	parse(argvlst, env);
}

void	parse(t_list *argvlst, t_env *env)
{
	t_list	*current;
	t_list	*prev;
	int		i;
	int		j;

	if (!(env->map = malloc(sizeof(int *) * env->maph)))
		exit_error("OOM");
	current = argvlst;
	i = 0;
	while (current)
	{
		if (!(env->map[i] = malloc(sizeof(int) * env->mapw)))
			exit(0);
		j = -1;
		while (++j < env->mapw)
			env->map[i][j] = ft_atoi(((char **)current->content)[j]);
		prev = current;
		current = current->next;
		ft_strstrfree(prev->content);
		free(prev);
		i++;
	}
	printf("%d %d\n", env->mapw, env->maph);
}
