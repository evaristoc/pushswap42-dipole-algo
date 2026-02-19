#include "engine.h"

/**
 * @brief
 */
t_list *list_create(char name)
{
	struct s_list *dll;

	dll = malloc(sizeof(*dll));
	if (!dll)
		return (NULL);
	dll->name = name;
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
	return (dll);
}
/**
 * @brief
 */
void list_destroy(t_list **list_ptr)
{
	t_list *ddl;
	t_node *current;
	t_node *next_node;

	if (!list_ptr || !(*list_ptr))
		return;
	ddl = *list_ptr;
	current = ddl->head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(ddl);
	*list_ptr = NULL;
}