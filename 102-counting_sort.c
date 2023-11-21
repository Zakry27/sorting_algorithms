#include "sort.h"
/**
 * counting_sort - it sorts array of ints in asc
 * order using Counting sort algorithm
 * @array: the pointer to array
 * @size: the size of array
 **/
void counting_sort(int *array, size_t size)
{
	int n, k, *count_arry, *auxi;
	size_t i;

	if (!array || size < 2)
		return;
	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	}
	count_arry = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_arry[array[i]]++;
	}
	for (k = 1; k < n; k++)
	{
		count_arry[k + 1] += count_arry[k];
	}
	print_array(count_arry, n + 1);
	auxi = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_arry[array[i]]--;
		auxi[count_arry[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = auxi[i];
	}
	free(auxi);
	free(count_arry);
}
