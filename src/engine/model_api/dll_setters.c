#include "engine.h"

int list_push_start(t_list *list, int value, int rank, int direction)
{
	t_node *new_node;

	if (!list)
		return (0);
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->rank = rank;
	new_node->direction = direction;
	new_node->next = list->head;
	new_node->prev = NULL;
	if (!list->head)
		list->tail = new_node;
	else
		list->head->prev = new_node;
	list->head = new_node;
	list->size += 1;
	return (1);
}

int list_push_end(t_list *list, int value, int rank, int direction)
{
	t_node *new_node;

	if (!list)
		return (0);
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->rank = rank;
	new_node->direction = direction;
	new_node->prev = list->tail;
	new_node->next = NULL;
	if (!list->tail)
		list->head = new_node;
	else
		list->tail->next = new_node;
	list->tail = new_node;
	list->size += 1;
	return (1);
}

int list_pop_start(t_list *list, int *out_value, int *out_rank, int *out_dir)
{
	t_node *old_node;

	if (!list || !list->head)
		return (0);
	old_node = list->head;
	if (out_value != NULL)
		*out_value = old_node->value;
	if (out_rank != NULL)
		*out_rank = old_node->rank;
	if (out_dir != NULL)
		*out_dir = old_node->direction;
	list->head = list->head->next;
	if (list->head == NULL)
		list->tail = NULL;
	else
		list->head->prev = NULL;
	free(old_node);
	list->size -= 1;
	return (1);
}

int list_pop_end(t_list *list, int *out_value, int *out_rank, int *out_dir)
{
	t_node *old_node;

	if (!list || !list->tail)
		return (0);
	old_node = list->tail;
	if (out_value != NULL)
		*out_value = old_node->value;
	if (out_rank != NULL)
		*out_rank = old_node->rank;
	if (out_dir != NULL)
		*out_dir = old_node->direction;
	list->tail = list->tail->prev;
	if (list->tail == NULL)
		list->head = NULL;
	else
		list->tail->next = NULL;
	free(old_node);
	list->size -= 1;
	return (1);
}
