#include "sort.h"
#include <stdio.h>

void quick_sort_3070(int *arr, size_t st, size_t ed);
size_t division(int *arr, size_t st, size_t up);

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

/**
 * quick_sort_3070 - the real quick sort function
 * @arr: the array
 * @lb: lower bound (the min index)
 * @ub: upper bound (the max index)
 * --------------------------------------------
*/
void quick_sort_3070(int *arr, size_t lb, size_t ub)
{
	size_t loc;

	if (lb < ub)
	{
		loc = division(arr, lb, ub);
		quick_sort_3070(arr, lb, loc - 1);
		quick_sort_3070(arr, loc + 1, ub);
	}
}

/**
 * division - manages the array partitions
 * @arr: the array
 * @st: starting path index
 * @up: upper bound (last index)
 * ----------------------------------
 * Return: location of the pivot index
*/
size_t division(int *arr, size_t st, size_t up)
{
	int pivot, aux;
	size_t ed = up;

	if (!arr)
		return (-1);
	pivot = arr[ed];
	while (st < ed)
	{

		while (arr[st] <= pivot)
			st++;
		while (arr[ed] > pivot)
			ed--;

		if (st < ed)
		{
			aux = arr[st];
			arr[st] = arr[ed];
			arr[ed] = aux;
			print_array(arr, up);
		}
	}

	aux = arr[ed];
	arr[ed] = pivot;
	arr[up] = aux;
	print_array(arr, up);

	return (ed);
}
	
