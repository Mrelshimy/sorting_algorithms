#include "sort.h"

/**
 * quick_sort - C implementation of selection sort algorithm
 * @array: input array to be sorted
 * @size: array size
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - sorting of array fn
 * @array: input array to be sorted
 * @size: array size
 * @start: lower bound
 * @end: higher bound
 *
 */
void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = partition(array, start, end, size);
	quicksort(array, start, pivot - 1, size);
	quicksort(array, pivot + 1, end, size);
}

/**
 * partition - partitioning of array
 * @array: input array to be sorted
 * @size: array size
 * @start: lower bound
 * @end: higher bound
 *
 * Return: pivot location
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j, tmp;

	(void) size;
	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[end];
	array[end] = tmp;
	print_array(array, size);
	return (i);
}
