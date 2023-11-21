#include "sort.h"
/**
 * check_tree - the swiftdown check
 * @array: the pointer to array
 * @size: the size of pointer
 * @size_init: the original size of array
 * @i: the index as root of tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, branc1, branc2;
	size_t brr1, brr2;

	brr1 = i * 2 + 1;
	brr2 = brr1 + 1;
	branc1 = array[brr1];
	branc2 = array[brr2];
	if (((brr1 < size) && (brr2 < size) &&
		(branc1 >= branc2 && branc1 > array[i]))
		|| ((brr1 == size - 1) && branc1 > array[i]))
	{
		n = array[i];
		array[i] = branc1;
		array[brr1] = n;
		print_array(array, size_init);
	}
	else if ((brr1 < size) && (brr2 < size) &&
		(branc2 > branc1 && branc2 > array[i]))
	{
		n = array[i];
		array[i] = branc2;
		array[brr2] = n;
		print_array(array, size_init);
	}
	if (brr1 < size - 1)
		check_tree(array, size_init, size, brr1);
	if (brr2 < size - 1)
		check_tree(array, size_init, size, brr2);
}
/**
 * heap_sort - it sorts array of ints
 * in asc order using Heap
 * sort algorithm
 * @array: the pointer to array
 * @size: the size of pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

}
