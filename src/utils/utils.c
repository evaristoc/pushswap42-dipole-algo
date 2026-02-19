#include "push_swap.h"

int ft_abs(int n1, int n2)
{
	int na;
	int nb;

	if (n1 < 0)
		na = -1 * n1;
	if (n2 < 0)
		nb = -1 * n2;
	if (na >= nb)
		return (na - nb);
	else
		return (nb - na);
}

int ft_min(int n1, int n2)
{
	if (n1 >= n2)
		return n2;
	return (n1);
}