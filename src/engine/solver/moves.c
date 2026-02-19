#include "engine.h"

int s(t_list *pile)
{
	if (!swap(pile))
		return (0);
	moves_logger(pile, __func__);
	return (1);
}

int p(t_list *src, t_list *dest)
{
	if (!push_btwn(src, dest))
		return (0);
	moves_logger(dest, __func__);
	return (1);
}
int r(t_list *pile)
{
	if (!rotate(pile))
		return (0);
	moves_logger(pile, __func__);
	return (1);
}

int rr(t_list *pile)
{
	if (!reverse_rotate(pile))
		return (0);
	moves_logger(pile, __func__);
	return (1);
}

int drr(t_list *pile1, t_list *pile2)
{
	if (!double_rotate(pile1, pile2))
		return (0);
	moves_logger(NULL, __func__ + 1);
	return (1);
}

int rrr(t_list *pile1, t_list *pile2)
{
	if (!double_rev_rotate(pile1, pile2))
		return (0);
	moves_logger(NULL, __func__);
	return (1);
}
