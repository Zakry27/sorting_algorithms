#include "sort.h"
/**
 * print_array - this prints array of ints
 *
 * @array: array to be printed
 * @size: the num of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
