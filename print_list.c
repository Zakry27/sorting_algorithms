#include "sort.h"
/**
 * print_list - this prints list of ints
 *
 * @list: list to be printed
 */
void print_list(const listint_t *list)
{
	int z;

	z = 0;
	while (list)
	{
		if (z > 0)
			printf(", ");
		printf("%d", list->n);
		++z;
		list = list->next;
	}
	printf("\n");
}
