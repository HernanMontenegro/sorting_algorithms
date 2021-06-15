#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 *                  ascending order using the Selection sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * ------------------------------------------
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, aux;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}

		if (min != i)
		{
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
			print_array(array, size);
		}
	}
}
