#include "sort.h"

/**
 * swap - swaps the values stored at two different addresses.
 * @xp: pointer to the address of the first value.
 * @yp: pointer to the address of the second value.
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm.
 * @array: an array of integers.
 * @size: the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
