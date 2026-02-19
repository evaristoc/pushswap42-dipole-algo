#include "push_swap.h"

char **get_input(int argc, char **argv)
{
	char **input;
	int index;

	index = 1;
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
	{
		input = ft_calloc(argc, sizeof(char *));
		if (!input)
			return (NULL);
		while (index < argc)
		{
			input[index - 1] = ft_strdup(argv[index]);
			index++;
		}
	}
	return (input);
}

int parser(int argc, char **argv, char ***gotinput_ptr)
{
	*gotinput_ptr = get_input(argc, argv);
	return (is_valid_input(*gotinput_ptr));
}