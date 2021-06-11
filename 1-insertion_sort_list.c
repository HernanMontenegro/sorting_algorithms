#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *					 in ascending order using the Insertion sort algorithm
 * @list: the list to sort
 * --------------------------------------
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *cu, *cu_p;

	if (!list)
		return;
	cu = (*list)->next;
	while (cu)
	{
		cu_p = cu->prev;
		while (cu_p && cu->n < cu_p->n)
		{
			if (!cu_p->prev)
			{
				cu->next->prev = cu->prev;
				cu->prev->next = cu->next;
				cu_p->prev = cu;
				cu->prev = NULL;
				cu->next = cu_p;
				(*list) = cu;
			}
			else
			{
				cu->prev->next = cu->next;
				if (cu->next)
					cu->next->prev = cu->prev;
				cu->next = cu_p;
				cu_p->prev->next = cu;
				cu->prev = cu_p->prev;
				cu_p->prev = cu;
			}
			print_list(*list);
			cu_p = cu->prev;
		}
		cu = cu->next;
	}
}
