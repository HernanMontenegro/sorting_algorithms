#include "sort.h"
#include <stdio.h>

/* My linked list */
void add_nodeint(indexlist_t **head, const int n);
int search_in_llist(indexlist_t *head, const int idx);

/**
 * quick_sort - quick sort sorting order
 * @array: array to sort
 * @size: the size of the array
 * ------------------------------------
*/
void quick_sort(int *array, size_t size)
{
	int pivot, aux, i;
	size_t bot, top = 0;
	indexlist_t *locked_idx = NULL;

	if (!array || size == 0)
		return;
	pivot = array[size - 1];

	for (i = 0; i < size; i++)
	{
		for (bot = 0; bot != size - 1; bot++, top++)
		{
			if (pivot >= array[bot] || search_in_llist(locked_idx, bot) == 1)
				continue;
			/* pivot < array[bot] - Ahora si se viene lo chido */
			top++;
			/* Loopeo hasta encontrar un valor apto para swapear */
			while (pivot < array[top] && top < size)
				top++;
			/* SWAP */
			aux = array[bot];
			array[bot] = array[top];
			array[top] = aux;
			bot = --top; /* -1 por el incremento del for */
		}
		/* bot - 1 por el incremento al final del for*/
		add_nodeint(&locked_idx, bot - 1);
		print_array(array, size);
	}
}

/**
* add_nodeint - add new node at the begining
* @head: the head node
* @n: the int value to add
* -------------------------------
* Return: a new node
*/
void add_nodeint(indexlist_t **head, const int n)
{
	indexlist_t *new_one;

	new_one = malloc(sizeof(indexlist_t));
	if (!new_one)
		return;
	new_one->n = n;
	new_one->next = (*head);

	*head = new_one;
}

/**
 * search_in_llist - search an index in the linked list
 * @head: the head node
 * @n: the index to find
 * -------------------------------
 * Return: 1 if index was found, -1 if not
*/
int search_in_llist(indexlist_t *head, const int idx)
{
    if (!head)
        return (-1);
    while (head)
    {
        if (head->n == idx)
            return (1);
        head = head->next;
    }
    return (-1);
}
