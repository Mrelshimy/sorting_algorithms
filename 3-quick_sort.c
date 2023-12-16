#include "sort.h"

/**
 * quick_sort - C implementation of selection sort algorithm
 * @array: input array to be sorted
 * @size: array size
 *
 * Description: This function sorts an array of integers
 *              in ascending order using the quicksort algorithm.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;

	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - Recursive function to perform quicksort
 * @array: input array to be sorted
 * @start: lower bound of the array or subarray
 * @end: upper bound of the array or subarray
 * @size: array size
 *
 * Description: This function is a helper function for quick_sort.
 *              It recursively sorts the array or subarray using quicksort.
 */
void q_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = partition(array, start, end, size);

	/* Uncomment the following line if you want to see intermediate steps */
	/* printf("After partition: "); print_array(array, size); */

	q_sort(array, start, pivot - 1, size);
	q_sort(array, pivot + 1, end, size);
}

/**
 * partition - Partitioning of array for quicksort
 * @array: input array to be sorted
 * @start: lower bound of the array or subarray
 * @end: upper bound of the array or subarray
 * @size: array size
 *
 * Return: pivot location
 *
 * Description: This function takes the last element of the array as the pivot,
 *              places the pivot element at its correct position in the sorted
 *              array, and places all smaller elements to the left of the pivot
 *              and all greater elements to the right of the pivot.
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			var_swap(array, size, &array[j], &array[i + 1]);
			i++;
		}
	}

	var_swap(array, size, &array[i + 1], &array[end]);
	return (i + 1);
}

/**
 * var_swap - Swap two elements in an array
 * @array: input array
 * @size: array size
 * @x: pointer to the first element
 * @y: pointer to the second element
 *
 * Description: This function swaps the values of two elements in an array
 *              and prints the array after the swap.
 */
void var_swap(int *array, size_t size, int *x, int *y)
{
	int tmp;

	if (x != y)
	{
		tmp = *x;
		*x = *y;
		*y = tmp;
		print_array(array, size);
	}
}
