#include "engine.h"

void update_meta_after_push(t_list *pile, t_3gdz_meta *meta)
{
	meta->b_max = find_max(pile);
	meta->b_min = find_min(pile);
	meta->median = median(pile);
}

int median(t_list *pile)
{
	int tsize;
	int med_pos;
	t_node *temp;
	int index;

	if (!pile || !pile->head || pile->size == 0)
		return (0);
	tsize = pile->size;
	if (tsize == 1)
		return (pile->head->rank);
	med_pos = tsize / 2;
	temp = pile->head;
	index = 0;
	while (temp && index <= med_pos)
	{
		med_pos = temp->rank;
		temp = temp->next;
	}
	return (med_pos);
}
