#include "sort.h"
/**
 * selection_sort - this sorts array of ints in asc order using
 * Selection sort algorithm
 * @array: the pointer to array
 * @size: the size of array
 **/
void selection_sort(int *array, size_t size)
{
	size_t z, w, n, l;
	int auxi, flags;

	if (array)
	{
		for (z = 0; z < size; z++)
		{
			auxi = array[z];
			flags = 0;
			for (w = z; w < size ; w++)
			{
				if (array[w] < auxi)
				{
					l = w;
					auxi = array[w];
					flags = 1;
				}
			}
			if (flags == 1)
			{
				n = array[z];
				array[z] = array[l];
				array[l] = n;
				print_array(array, size);
			}
		}
	}
}
