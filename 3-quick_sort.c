#include "sort.h"
/**
 * quick_sort_rec - it sorts array of ints in asc order using
 * Selection sort algo using recursion
 * @array: the pointer to array
 * @size: the size of array
 * @array_init: the initial pointer to array
 * @size_init: the initial size of array
 **/
void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size)
{
	size_t j, aux1;
	int aux2;
	int z = -1, n, pivot = array[size - 1];

	if (array && size > 1)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] < pivot)
			{
				z++;
				aux1 = z;
				if (aux1 != j && array[j] != array[aux1])
				{
					n = array[j];
					array[j] = array[z];
					array[z] = n;
					print_array(array_init, size_init);
				}
			}


		}
		aux2 = size;
		if (aux2 - 1 != z + 1 && array[aux2 - 1] != array[z + 1])
		{
			array[size - 1] = array[z + 1];
			array[z + 1] = pivot;
			print_array(array_init, size_init);
		}
		if (z > 0)
		{
			quick_sort_rec(array_init, size_init, array, z + 1);
		}
		quick_sort_rec(array_init, size_init, array + z + 2,  size - (z + 2));
	}
}
/**
 * quick_sort - it sorts array of ints in asc order using
 * Selection sort algo
 * @array: the pointer to array
 * @size: the size of array
**/
void quick_sort(int *array, size_t size)
{
	int *array_init;
	size_t size_init;

	if (array)
	{
		array_init = array;
		size_init = size;
		quick_sort_rec(array_init, size_init, array, size);
	}
}
