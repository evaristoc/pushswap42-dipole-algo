#include "engine.h"

int solver(t_list *a, t_list *b)
{
	if (!ranker(a))
		return (0);
	if (a->size <= 3)
		return (sort_less_three(a));
	else if (a->size <= 5)
		return (sort_five(a, b));
	else
	{
		return (sort_big(a, b));
	}
}
