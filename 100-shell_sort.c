#include "sort.h"
/**
 * shell_sort - this sorts array of ints in
 * asc order using Shell sort algorithm,
 * by using Knuth sequence
 * @array: the pointer to array
 * @size: the size of array
 **/
void shell_sort(int *array, size_t size)
{
	size_t kunth[1000], k = 0, l = 0, z;
	int n, j;

	if (!array)
		return;
	while (l * 3 + 1 < size)
	{
		kunth[k] = l * 3 + 1;
		l = kunth[k++];
	}
	for (z = 0; z < k; z++)
	{
		for (l = 0; l < size; l++)
		{
			if ((l + kunth[k - z - 1]) > size - 1)
				break;
			j = l;
			while (array[j] > array[j + kunth[k - z - 1]])
			{
				n = array[j];
				array[j] =  array[j + kunth[k - z - 1]];
				array[j + kunth[k - z - 1]] = n;
				j = j - kunth[k - z - 1];
				if (j < 0)
					break;
			}
		}
		print_array(array, size);
	}
}
