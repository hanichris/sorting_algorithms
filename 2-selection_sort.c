#include "sort.h"

/**
 * swap - swaps the contents of two different memory addresses.
 * @xptr: memory address of an integer variable.
 * @yptr: memory address of an integer variable.
 */
void swap(int *xptr, int *yptr)
{
	int temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
}

/**
 * selection_sort - performs sorting using the selection sort
 * algorithm.
 * @array: array of integers to be sorted in ascending order.
 * @size: size of the array to sort.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
