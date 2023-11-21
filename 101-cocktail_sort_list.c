#include "sort.h"
/**
 * swap1 - it swaps nodes from left to right
 * @list: the pointer to list
 * @head: pointer directed towards head node
 * @aux: the auxiliar pointer
 * Return: nothing
 */
void swap1(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);

}
/**
 * swap2 - it swaps nodes from right to left
 * @list: the pointer to list
 * @head: pointer directed towards head node
 * @aux: the auxiliar pointer
 * Return: nothing
 */
void swap2(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * cocktail_sort_list - it sorts doubly linked list of ints
 * in asc order using Cocktail sort ailgorithm
 * @list: pointer to list head
 * Return: nothing
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *heads, *auxx;
	int flags = 1;

	if (list)
	{
		heads = *list;
		while (flags != 0)
		{
			flags = 0;
			while (heads->next)
			{
				if (heads->n > heads->next->n)
				{
					auxx = heads->next;
					swap1(list, heads, auxx);
					flags = 1;
				}
				else
					heads = heads->next;
			}
			if (flags == 0)
				break;
			flags = 0;
			while (heads->prev)
			{
				if (heads->prev->n > heads->n)
				{
					swap2(list, heads, auxx);
					flags = 1;
				}
				else
					heads = heads->prev;
			}

		}
	}
}
