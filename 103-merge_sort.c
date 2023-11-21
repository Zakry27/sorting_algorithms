#include "sort.h"
/**
 * merge - it merges l and r arrays into an original array
 * @array: the pointer to array
 * @size: the size of array
 * @l: the pointer to the left array
 * @r: the pointer to the right array
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int d = 0, i = 0, v = 0;
	int size_ll, size_rr;

	size_ll = size / 2;
	size_rr = size - size_ll;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_ll);
	printf("[right]: ");
	print_array(r, size_rr);

	while (i < size_ll && d < size_rr)
	{
		if (l[i] < r[d])
			array[v++] = l[i++];
		else
			array[v++] = r[d++];
	}

	while (i < size_ll)
		array[v++] = l[i++];

	while (d < size_rr)
		array[v++] = r[d++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - it sorts array of ints in asc order using
 * Merge sort algorithm
 * @array: the pointer to array
 * @size: the size of array
 **/
void merge_sort(int *array, size_t size)
{
	size_t midd = 0, v;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	midd = size / 2;

	for (v = 0; v < midd; v++)
		left[v] = array[v];

	for (v = midd; v < size; v++)
		right[v - midd] = array[v];

	merge_sort(left, midd);
	merge_sort(right, size - midd);
	merge(array, left, right, size);
}
