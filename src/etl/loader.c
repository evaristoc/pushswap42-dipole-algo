#include "push_swap.h"

int loader(t_list **a, char **input, char name)
{
	int index;
	int errorpush;
	int value;

	index = 0;
	if (!input)
		return (0);
	*a = list_create(name);
	while (input[index] != NULL)
	{
		value = ft_atoi(input[index]);
		if (is_duplicate(*a, value))
			return (0);
		errorpush = list_push_end(*a, value, -1, 1);
		if (!errorpush)
			return (0);
		index++;
	}
	return (1);
}
