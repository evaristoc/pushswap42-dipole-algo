#include "engine.h"

void moves_logger(t_list *pile, const char *funcname)
{
	char c;

	write(1, funcname, ft_strlen(funcname));
	if (pile)
	{
		c = pile->name;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}