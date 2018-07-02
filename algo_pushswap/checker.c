
#include <pushswap.h>

int main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	// check errors function check_errors(argc, argv)
	if (argc < 2){}
		// error
	if (!valid_args(argc, argv)){}
		// error
	// add malloc guards
	a.table = (int *)malloc(sizeof(int) * (argc - 1));
	b.table = (int *)malloc(sizeof(int) * (argc - 1));
	a.top = 0;
	b.top = 0;

	// push all args onto stack after error checking
	int			i;
	i = argc - 1;
	while (i > 0)
	{
		st_push(&a, ft_atoi(argv[i]));
		i--;
	}
	// read from stdin
	
	char		*l;
	char		**cmds;
	int			contains = 0;
	int			i;
	// get_commands();
	if (!(cmds = ft_strsplit("sa sb ss pa pb pb ra rb rr rra rrb rrr", ' '))){}
		// error-
	while (get_next_line(0, &l))
	{
		// create function that checks whether line contains cmds
		while (i < )
		
	}
}

int		valid_args(int argc, char **argv)
{
	if (valid_nums(argc, argv) == 0)
		return (0);
	if (valid_dups(argc, argv) == 0)
		return (0);
	return (1);
}

// TODO add to libft stringarr numeric check
int		valid_nums(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];

			if (!(ft_isdigit(c)))
				if (!(j == 0 && (c == '-' || c == '+')))
					return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

// TODO add to libft stringarr dupliccates check
int		valid_dups(int argc, char **argv)
{
	int		i;
	int		j;
	
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j] < 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

