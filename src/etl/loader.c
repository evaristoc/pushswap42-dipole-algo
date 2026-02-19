#include "push_swap.h"

// char *trimmer(char const *str, char const *set)
// {
// 	char const *strpnt;
// 	size_t trimbuffer;

// 	strpnt = str;
// 	if (!str || !set)
// 		return (NULL);
// 	if (ft_strlen(str) == 0)
// 		return (ft_strdup(""));
// 	while (*strpnt && (ft_strchr(set, *strpnt)))
// 		strpnt++;
// 	trimbuffer = ft_strlen(strpnt);
// 	if (*strpnt)
// 		return (ft_substr(strpnt, 0, trimbuffer + 1));
// 	else
// 		return (ft_strdup(""));
// }

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
