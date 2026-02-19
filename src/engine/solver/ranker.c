#include "engine.h"

static int ranks_map_list(int *array, t_list *list)
{
	int size;
	int index;
	t_node *target;

	size = list->size;
	if (!list || !list->head)
		return (0);
	index = 0;
	while (index < size)
	{
		target = list->head;
		while (target != NULL)
		{
			if (target->value == array[index])
			{
				target->rank = index;
				break;
			}
			target = target->next;
		}
		index++;
	}
	return (1);
}

static void sorted_array(int *array, int lenranker)
{
	int i;
	int j;
	int selecttemp;

	i = 0;
	while (i < lenranker)
	{
		j = i + 1;
		while (j < lenranker)
		{
			if (array[i] > array[j])
			{
				selecttemp = array[i];
				array[i] = array[j];
				array[j] = selecttemp;
			}
			j++;
		}
		i++;
	}
}

int ranker(t_list *a)
{
	int *ranked;

	ranked = list_to_array(a);
	if (!ranked)
		return (0);
	sorted_array(ranked, a->size);
	if (!ranks_map_list(ranked, a))
	{
		free(ranked);
		ranked = NULL;
		return (0);
	}
	free(ranked);
	ranked = NULL;
	return (1);
}