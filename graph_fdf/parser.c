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

void	parse_args(int argc, char **argv, t_env *env)
{
	t_list	*argvlst;
	char	**str;
	char	*l;
	int		fd;

	if (argc != 2)
		exit(0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit(0);
	get_next_line(fd, &l);
	free(l);
	str = ft_strsplit(l, ' ');
	argvlst = ft_lstnew(str);
	env->mapw = ft_strstrlen(str);
	env->maph = 1;
	while (get_next_line(fd, &l))
	{
		str = ft_strsplit(l, ' ');
		ft_lstappend(&argvlst, ft_lstnew(str));
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
}
