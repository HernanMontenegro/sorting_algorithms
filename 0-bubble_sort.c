#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * --------------------------------------
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int aux = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j + 1];
				array[j + 1] = array[j];
				array[j] = aux;
			}
		}
		print_array(array, size);
	}
}
