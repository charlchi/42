
#include "pushswap.h"

int main(int argc, char **argv)
{
	int			*ops;
	t_search	**searches;
	t_stack		a;
	t_stack		b;

	parse_args(&a, &b, argc, argv);
	if (argc == 2)
		return (0);
	searches = (t_search **)malloc(sizeof(t_search *) * 3);
	searches[0] = min_algo(a, b);
	searches[1] = algo1(a, b);
	searches[2] = NULL;
	ops = print_smallest_ops(searches);
	free_searches(searches);
	free(a.table);
	free(b.table);
	return (0);
}