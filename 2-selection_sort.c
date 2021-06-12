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
	size_t i, j;
	int min = 0;

	for (i = 0; i < size; i++)
	{
		min = array[i + 1];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
				min = array[j];
		}
		for (j = i + 1; j < size; j++)
		{
			if (min == array[j] && array[i] > min)
			{
				array[j] = array[i];
				array[i] = min;
				break;
			}
		}
		print_array(array, size);
	}
}
