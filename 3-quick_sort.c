#include "sort.h"

void quick_sort_3070(int *arr, int lb, int up, size_t size);
int division(int *arr, int lb, int up, size_t size);


/**
* quick_sort - sort function using quick sort algoritmh
* @array: array received
* @size: size of array
* -----------------------------
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_3070(array, 0, size - 1, size);
}

/**
 * quick_sort_3070 - original function of quick sort
 * @arr: array received
 * @lb: lower bound (min index)
 * @up: upper bound (max  index)
 * @size: size of array
 * ----------------------------------
 */
void quick_sort_3070(int *arr, int lb, int up, size_t size)
{
	int p;

	if (lb < up)
	{
		p = division(arr, lb, up, size);
		quick_sort_3070(arr, lb, p - 1, size);
		quick_sort_3070(arr, p + 1, up, size);
	}
}

/**
 * division - manages the division of the array
 * @arr: array received
 * @lb: lower bound (min index)
 * @up: upper bound (max  index)
 * @size: size of array
 * -------------------------------------
 * Return: location where pivot was inserted
 */
int division(int *arr, int lb, int up, size_t size)
{
	int pivot, aux, j = lb, i = lb;

	pivot = arr[up];
	while (j <= up)
	{
		if (arr[j] < pivot)
		{
			aux = arr[j];
			arr[j] = arr[i];
			arr[i] = aux;
			if (i != j)
				print_array(arr, size);
			i++;
		}
		j++;
	}
	aux = arr[i];
	arr[i] = arr[up];
	arr[up] = aux;
	if (arr[up] != pivot)
		print_array(arr, size);
	return (i);
}
