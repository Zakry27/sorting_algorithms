#include "sort.h"
/**
 * bubble_sort - this is to sort array of ints in asc order using
 * Bubble sort algo
 * @array: the pointer to array
 * @size: the size of array
 **/
void bubble_sort(int *array, size_t size)
{
	size_t a, b, n;

	for (a = 0; a < size; a++)
	{
		for (b = 1; b < size - a; b++)
		{
			if (array[b - 1] > array[b])
			{
				n = array[b];
				array[b] = array[b - 1];
				array[b - 1] = n;
				print_array(array, size);
			}
		}
	}
}
