
#include "pushswap.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		// error
	if (!valid_args(argc, argv))
		// error
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

int main(int argc, char **argv)
{
	if (argc < 2)
		// error
	if (!valid_args(argc, argv))
		// error
	// push args to stack starting from (argc) to (0 + 1)
	
}
