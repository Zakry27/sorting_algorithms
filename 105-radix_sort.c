#include "sort.h"
/**
 * max_val - this gets max value from array
 * @array: the pointer to array
 * @size: the size of array
 * Return: the max value from array
 */
int max_val(int *array, size_t size)
{
	int maxx = array[0];
	size_t v;

	for (v = 0; v < size; v++)
	{
		if (array[v] > maxx)
			maxx = array[v];
	}
	return (maxx);
}
/**
 * radix_sort - it sorts array of ints is asc
 * order implementing the Radix Sort algorithm
 * @array: the pointer to array
 * @size: the size of array
 */
void radix_sort(int *array, size_t size)
{
	int *new_array;
	int z, maxi, e = 1;
	int tamm = size;

	if (!array || size < 2)
		return;

	maxi = max_val(array, size);

	new_array = malloc(sizeof(int) * size);
	while (maxi / e > 0)
	{
		int brews[20] = {0};

		z = 0;

		while (z < tamm)
		{
			brews[(array[z] / e) % 10]++;
			z++;
		}

		if (brews != NULL)
		{
			for (z = 1; z < 10; z++)
				brews[z] += brews[z - 1];

			for (z = tamm - 1; z >= 0; z--)
			{
				new_array[brews[(array[z] / e) % 10] - 1] = array[z];
				brews[(array[z] / e) % 10]--;
			}

			for (z = 0; z < tamm; z++)
				array[z] = new_array[z];
		}
		e *= 10;
		print_array(array, size);
	}
	free(new_array);
}
