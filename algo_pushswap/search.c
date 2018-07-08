
t_search	*malloc_search(t_stack *a, t_stack *b);
{
	t_search	*ret;

	ret = (t_search *)malloc(sizeof(t_search));
	ret->n = 0;
	ret->ops = (int *)malloc(sizeof(int) * 100000);
	init_stack(ret->a, a->top + 1);
	init_stack(ret->b, a->top + 1);
	copy_stack(a, ret->a);
	return (ret);
}

void		search_do_op(t_search *search, int op)
{
	search->ops[search->n] = op;
	search->n++;
	do_cmd(search->a, search->b, op);
}

int		*print_smallest_ops(t_search **searches)
{
	int		i;
	int		min;
	int		min_i;
	char	**cmds;

	min = searches[0]->n;
	min_i = 0;
	i = 0;
	while (searches[++i])
	{
		if (searches[i]->n < min)
		{
			min = searches[i]->n;
			min_i = i;
		}
	}
	if (!(cmds = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ')))
		exit_error();
	while (i < min)
	{
		write(1, cmds[searches->ops[i] - 1], ft_strlen(cmds[searches->ops[i] - 1]));
		write(1, "\n", 1);
	}
	free(cmds);
}

void		free_searches(t_search **searches)
{
	int		i;

	i = 0;
	while (searches[i])
	{
		free(searches[i]->ops);
		free(searches[i]->a->table);
		free(searches[i]->b->table);
		i++;
	}
	free(searches);
}

