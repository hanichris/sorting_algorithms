#include "sort.h"

/**
 * swap - swaps the elements of two memory addresses.
 * @xptr: address of the first variable.
 * @yptr: address of the second variable.
 */
void swap(int *xptr, int *yptr)
{
	int temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
}

/**
 * partition - partition the array using the Lomuto partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @low_idx: lower index of the array.
 * @high_idx: upper index of the array.
 * Return: index of the pivot element withing the sorted array.
 */
int partition(int *array, size_t size, int low_idx, int high_idx)
{
	int i;
	int p;
	int firsthigh;

	firsthigh = low_idx;
	p = high_idx;
	for (i = low_idx; i < high_idx; i++)
		if (array[i] < array[p])
		{
			swap(&array[i], &array[firsthigh]);
			firsthigh++;
		}
	swap(&array[firsthigh], &array[p]);
	print_array(array, size);
	return (firsthigh);
}

/**
 * quicksort - employs the partitioning approach to sort each subarray.
 * @array: array of integers.
 * @size: size of the array.
 * @low_idx: lower index of the array.
 * @high_idx: higher index of the array.
 */
void quicksort(int *array, size_t size, int low_idx, int high_idx)
{
	int p_idx;

	if ((high_idx - low_idx) > 0)
	{
		p_idx = partition(array, size, low_idx, high_idx);
		quicksort(array, size, low_idx, p_idx - 1);
		quicksort(array, size, p_idx + 1, high_idx);
	}
}

/**
 * quick_sort - wrapper for the quicksort algorithm.
 * @array: array of integers to sort.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
