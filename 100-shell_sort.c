#include "sort.h"

/**
 * shell_sort - C implementation of shell sort algorithm
 * @array: input array to be sorted
 * @size: array size
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i, j;
	int tmp;

	if (array == NULL || size == 0)
		return;

	for (gap = get_gap(size); gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}

/**
 * get_gap - get maximum gap to trverse the array
 * @size: array size
 *
 * Return: max gap
 */
size_t get_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = (gap * 3) + 1;
	return ((gap - 1) / 3);
}
