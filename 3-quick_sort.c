#include "sort.h"
#include <stdio.h>

void quick_sort_3070(int *arr, size_t st, size_t ed);

/**
 * quick_sort - quick sort sorting order
 * @array: array to sort
 * @size: the size of the array
 * ------------------------------------
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_3070(array, 0, size - 1);
}

void quick_sort_3070(int *arr, size_t st, size_t ed)
{
	int pivot, i, j, aux;

	if (!arr)
		return;
	pivot = array[ed];

	for (; st < size; st++)
	{
		if (pivot >= array[st])
			continue;
		
		while (ed >= 0)
		{
			if (st > ed)
			{
				aux = array[ed];
				array[ed] = pivot;
				array[size - 1] = aux;
				break;
			}
			if (pivot < array[ed])
			{
				ed--;
				continue;
			}
			aux = array[st];
			array[st] = array[ed];
			array[ed] = array[st];
			break;
		}
		/* for avoid increment */
		st--;
	}
}
