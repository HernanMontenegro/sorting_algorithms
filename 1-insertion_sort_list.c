#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * 						 in ascending order using the Insertion sort algorithm
 * @list: the list to sort 
 * --------------------------------------
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *cu, *cu_p, *aux;

	if (!list)
		return;
	cu = (*list)->next;
	while (cu)
	{
		cu_p = cu->prev;
		if (cu->n >= cu_p->n)
		{
			cu = cu->next;
			cu_p = cu->prev;
			continue;
		}
		while (cu_p->prev && cu->n < cu_p->prev->n)
			cu_p = cu_p->prev;
		if (!cu_p->prev)
		{
			cu->next->prev = cu->prev;
			cu->prev->next = cu->next;
			aux = cu->next;
			cu_p->prev = cu;
			cu->prev = NULL;
			cu->next = cu_p;
			(*list) = cu;
			cu = aux;
		}
		else
		{
			cu_p->next = cu->next;
			if (cu->next)
				cu->next->prev = cu_p;
			cu->next = cu_p;
			cu->prev = cu_p->prev;
			cu_p->prev->next = cu;
			cu_p->prev = cu;
			cu = cu_p->next;
		}
		print_list(*list);
	}
}
