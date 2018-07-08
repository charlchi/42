
#include "pushswap.h"

int		main(int argc, char **argv)
{

	t_stack		a;
	t_stack		b;

	parse_args(&a, &b, argc, argv);
	run_checker(&a, &b);
	free(a.table);
	free(b.table);
	return (0);
}

void	run_checker(t_stack *a, t_stack *b)
{
	char		*l;
	char		**cmds;
	int			cmd;

	if (!(cmds = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ')))
		exit_error();
	while (get_next_line(0, &l))
	{
		if ((cmd = get_cmd(l, cmds)))
			do_cmd(a, b, cmd);
		else
			exit_error();
	}
	if (is_sorted(a->table, a->top) && b->top == -1)
		write(1, "OK\n", 3);
	else 
		write(1, "KO\n", 3);
	ft_strstrfree(cmds);
}

int		get_cmd(char *l, char **cmds)
{
	int		i;

	i = 0;
	while (cmds[i])
	{
		if (ft_strcmp(l, cmds[i]) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}