#include "push_swap.h"

/**
 * @brief void: when the Orchestrator calls etl_cleanup,
 * it is already at the end of a lifecycle (either
 * a successful finish or an error exit). If the
 * cleanup failed and sent an error signal back, the
 * Orchestrator would have no further "upward" path
 * to handle that new error.
 */
void input_arr_destroy(char ***gotinput)
{
	int index;

	if (gotinput == NULL || *gotinput == NULL)
		return;
	index = 0;
	while ((*gotinput)[index] != NULL)
	{
		free((*gotinput)[index]);
		(*gotinput)[index] = NULL;
		index++;
	}
	free(*gotinput);
	*gotinput = NULL;
}
