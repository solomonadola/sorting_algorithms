#include "sort.h"

/**
 * insertion_sort_list - insertion sorting algorithm
 * @list: linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nxt;

	if (list == NULL || *list == NULL)
		return;

	nxt = (*list)->next;

	while (nxt != NULL)
	{
		while (nxt->prev && nxt->prev->n > nxt->n)
		{
			nxt->prev->next = nxt->next;
			if (nxt->next)
				nxt->next->prev = nxt->prev;
			nxt->next = nxt->prev;
			nxt->prev = nxt->next->prev;
			nxt->next->prev = nxt;

			if (nxt->prev == NULL)
				*list = nxt;
			else
				nxt->prev->next = nxt;

			print_list(*list);
		}
		nxt = nxt->next;
	}
}
