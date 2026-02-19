#include "engine.h"

int is_duplicate(t_list *list, int value)
{
	t_node *current;

	if (!list || !list->head)
		return (0);
	current = list->head;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int *list_to_array(t_list *list)
{
	int *array;
	int index;
	t_node *current;

	if (!list || !list->head)
		return (NULL);
	array = malloc(list->size * (sizeof(int)));
	current = list->head;
	index = 0;
	if (!array)
		return (NULL);
	while (current != NULL)
	{
		array[index] = current->value;
		current = current->next;
		index++;
	}
	return (array);
}

int is_sorted(t_list *a)
{
	t_node *current;

	if (!a->head || !a->head->next)
		return (1);
	current = a->head;
	while (current->next != NULL)
	{
		if (current->next->value < current->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int find_max(t_list *p)
{
	int max;
	t_node *temp;

	if (!p || !p->head)
		return (-1);
	max = p->head->rank;
	temp = p->head->next;
	while (temp)
	{
		if (temp && temp->rank > max)
			max = temp->rank;
		temp = temp->next;
	}
	return (max);
}

int find_min(t_list *p)
{
	int min;
	t_node *temp;

	if (!p || !p->head)
		return (-1);
	min = p->head->rank;
	temp = p->head->next;
	while (temp)
	{
		if (temp && temp->rank < min)
			min = temp->rank;
		temp = temp->next;
	}
	return (min);
}
