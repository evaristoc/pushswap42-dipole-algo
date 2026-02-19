#include "push_swap.h"
#include <stdio.h>

static void cleaner(char ***input, t_list **a, t_list **b)
{
	if (input && *input)
	{
		input_arr_destroy(input);
		*input = NULL;
	}
	if (a && *a)
		list_destroy(a);
	if (b && *b)
		list_destroy(b);
}

int main(int argc, char **argv)
{
	char **inputs;
	t_list *a;
	t_list *b;

	inputs = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (parser(argc, argv, &inputs) == 0)
	{
		cleaner(&inputs, &a, &b);
		return (report_error());
	}
	if (loader(&a, inputs, 'a') == 0)
	{
		cleaner(&inputs, &a, &b);
		return (report_error());
	}
	if (is_sorted(a) == 1)
	{
		cleaner(&inputs, &a, &b);
		return (0);
	}
	b = list_create('b');
	// if (!b)
	// {
	// 	cleaner(&inputs, &a, &b);
	// 	return (report_error());
	// }
	if (solver(a, b) == 0)
	{
		cleaner(&inputs, &a, &b);
		return (report_error());
	}
	cleaner(&inputs, &a, &b);
	return (1);
}
