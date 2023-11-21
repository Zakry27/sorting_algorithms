#include "sort.h"
/**
 * insertion_sort_list - it sorts doubly linked list of ints
 * in asc order using Insertion sort algo
 * @list: the pointer to list head
 * Return: nothing
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *head_tm1, *head_tm2, *auxi1, *auxi2;
	int flags;

	if (list)
	{
		head_tm1 = *list;
		head_tm2 = *list;
		while (list && head_tm1->next)
		{
			if (head_tm1->next)
			{
				flags = 0;
				head_tm2 = head_tm1;
				while (head_tm2 && head_tm2->n > head_tm2->next->n)
				{
					auxi1 = head_tm2;
					auxi2 = head_tm2->next;
					auxi1->next = auxi2->next;
					if (auxi2->next)
						auxi2->next->prev = auxi1;
					if (auxi2)
					{
						auxi2->prev = auxi1->prev;
						auxi2->next = auxi1;
					}
					if (auxi1)
						auxi1->prev = auxi2;
					if (auxi2->prev)
						auxi2->prev->next = auxi2;
					head_tm2 = auxi2->prev;
					if (!auxi2->prev)
						*list = auxi2;
					print_list(*list);
					flags = 1;
				}
			}
			if (flags == 0)
				head_tm1 = head_tm1->next;
		}
	}
}
