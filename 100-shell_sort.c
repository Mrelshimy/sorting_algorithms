#include "sort.h"

/**
 * shell_sort - C implementation of shell sort algorithm
 * @array: input array to be sorted
 * @size: array size
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t k_gap;
	size_t i, j;
	int tmp;

	if (array == NULL || size == 0)
		return;

	for (k_gap = get_gap(size); k_gap > 0; k_gap = (k_gap - 1) / 3)
	{
		for (i = k_gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > k_gap - 1 && array[j - k_gap] > tmp; j -= k_gap)
				array[j] = array[j - k_gap];
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
