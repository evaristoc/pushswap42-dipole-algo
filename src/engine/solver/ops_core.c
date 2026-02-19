#include "engine.h"

int swap(t_list *pile)
{
	int swap_val;
	int swap_rank;
	int orient;

	if (!pile || !pile->head)
		return (0);
	if (!pile->head->next)
		return (1);
	swap_val = pile->head->value;
	swap_rank = pile->head->rank;
	orient = pile->head->orientation;
	pile->head->value = pile->head->next->value;
	pile->head->rank = pile->head->next->rank;
	pile->head->orientation = pile->head->next->orientation;
	pile->head->next->value = swap_val;
	pile->head->next->rank = swap_rank;
	pile->head->next->orientation = orient;
	return (1);
}

int rotate(t_list *pile)
{
	int rot_val;
	int rot_rank;
	int orient;

	if (!list_pop_start(pile, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_end(pile, rot_val, rot_rank, orient))
		return (0);
	return (1);
}

int reverse_rotate(t_list *pile)
{
	int rot_val;
	int rot_rank;
	int orient;

	if (!list_pop_end(pile, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_start(pile, rot_val, rot_rank, orient))
		return (0);
	return (1);
}

int push_btwn(t_list *src, t_list *dest)
{
	int rot_val;
	int rot_rank;
	int orient;

	if (!list_pop_start(src, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_start(dest, rot_val, rot_rank, orient))
		return (0);
	return (1);
}

int double_rotate(t_list *pile1, t_list *pile2)
{
	int rot_val;
	int rot_rank;
	int orient;

	if (!list_pop_start(pile1, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_end(pile1, rot_val, rot_rank, orient))
		return (0);
	rot_val = -1;
	rot_rank = -1;
	orient = 0;
	if (!list_pop_start(pile2, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_end(pile2, rot_val, rot_rank, orient))
		return (0);
	return (1);
}

int double_rev_rotate(t_list *pile1, t_list *pile2)
{
	int rot_val;
	int rot_rank;
	int orient;

	if (!list_pop_end(pile1, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_start(pile1, rot_val, rot_rank, orient))
		return (0);
	if (!list_pop_end(pile2, &rot_val, &rot_rank, &orient))
		return (0);
	if (!list_push_start(pile2, rot_val, rot_rank, orient))
		return (0);
	return (1);
}