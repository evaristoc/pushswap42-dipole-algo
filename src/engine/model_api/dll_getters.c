#include "engine.h"

int get_stack_size(t_list *list)
{
	if (!list)
		return (0);
	return (list->size);
}

void *get_head(t_list *list)
{
	return ((void *)list->head);
}

void *get_tail(t_list *list)
{
	return ((void *)list->tail);
}
void *get_next(void *node)
{
	t_node *next;
	t_node *current;

	current = (t_node *)node;
	if (current == NULL)
		return (NULL);
	next = current->next;
	return ((void *)next);
}

void *get_prev(void *node)
{
	t_node *prev;
	t_node *current;

	current = (t_node *)node;
	if (current == NULL)
		return (NULL);
	prev = current->prev;
	return ((void *)prev);
}
