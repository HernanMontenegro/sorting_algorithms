#include "sort.h"

void quick_sort_3070(int *arr, int lb, int up, size_t size);
int partition(int *arr, int lb, int up, size_t size);


/**
* quick_sort - sort function using quick sort algoritmh
* @array: array received
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_3070(array, 0, size - 1, size);
}

/**
 * quick_sort_3070 - original function of quick sort
 * @A: array received
 * @lb: menor indice
 * @up: mayor indice
 * @size: size of array
 */
void quick_sort_3070(int *arr, int lb, int up, size_t size)
{
	int p;

	if (lb < up)
	{
		p = partition(arr, lb, up, size);
		quick_sort_3070(arr, lb, p - 1, size);
		quick_sort_3070(arr, p + 1, up, size);
	}
}

/**
 * partition - partition function
 * @A: array received
 * @lb: menor indice
 * @up: mayor indice
 * @size: size of array
 * Return: i
 */
int partition(int *arr, int lb, int up, size_t size)
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
