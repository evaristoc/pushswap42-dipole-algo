#include "push_swap.h"

static int lexicographicalcmp(char *strcpy, int sign)
{
	size_t lnstr;

	if (!strcpy)
		return (1);
	lnstr = ft_strlen(strcpy);
	if (lnstr < 10)
		return (1);
	else if (sign)
		return (ft_strcmp(strcpy, INTMIN) <= 0);
	return (ft_strcmp(strcpy, INTMAX) <= 0);
}

static int is_valid_char(char *src)
{
	char *strcpy;
	size_t len;
	int sign;

	len = 0;
	sign = 0;
	if (*src == '-' || *src == '+')
	{
		if (*src == '-')
			sign = 1;
		src++;
	}
	while (*src == '0' && *(src + 1))
		src++;
	strcpy = src;
	if (ft_strlen(strcpy) > 10)
		return 0;
	while (strcpy[len])
	{
		if (!ft_isdigit(strcpy[len]))
			return (0);
		len++;
	}
	return (lexicographicalcmp(strcpy, sign));
}

int is_valid_input(char **input)
{
	int index;

	if (!input)
		return 0;
	index = 0;
	while (input[index] != NULL)
	{
		if (input[index][0] == '\0')
			return (0);
		if (!is_valid_char(input[index]))
			return (0);
		if (ft_strlen(input[index]) == 1 && (input[index][0] == '+' || input[index][0] == '-'))
			return (0);
		index++;
	}
	if (index == 0)
		return (0);
	return (1);
}
