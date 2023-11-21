#include "deck.h"
/**
 * aux_num_fun - this turns into int card value
 * @head_tmp1: the pointer to list
 * Return: the integer rep
 **/
int aux_num_fun(deck_node_t *head_tmp1)
{
	int auxi_num, z;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
		'8', '9', '1', 'J', 'Q', 'K'};

	for (z = 0; z < 13; z++)
	{
		if (head_tmp1->card->value[0] == val[z])
			auxi_num = num[z];
	}

	return (auxi_num);
}
/**
 * num_sort - it sorts doubly linked list of ints, 4 stages
 * @list: the pointer to list head
 * Return: nothing
 **/
void num_sort(deck_node_t **list)
{
	deck_node_t *head_tp1, *head_tp2, *auxi1, *auxi2;
	int flags = 0, i, auxi_num1, auxi_num2;
	unsigned int k;

	head_tp1 = *list;
	head_tp2 = *list;
	for (i = 0; i < 4; i++)
	{ k =  head_tp1->card->kind;
		while (head_tp1->next && head_tp1->next->card->kind == k)
		{
			auxi_num1 = aux_num_fun(head_tp1);
			auxi_num2 = aux_num_fun(head_tp1->next);
			flags = 0;
			head_tp2 = head_tp1;
			while (head_tp2 && head_tp2->card->kind == k && auxi_num1 > auxi_num2)
			{
				auxi1 = head_tp2;
				auxi2 = head_tp2->next;
				auxi1->next = auxi2->next;
				if (auxi2->next)
					auxi2->next->prev = auxi1;
				auxi2->prev = auxi1->prev;
				auxi2->next = auxi1;
				auxi1->prev = auxi2;
				if (auxi2->prev)
					auxi2->prev->next = auxi2;
				head_tp2 = auxi2->prev;
				if (!auxi2->prev)
					*list = auxi2;
				flags = 1;
				if (!head_tp2)
					break;
				auxi_num1 = aux_num_fun(head_tp2);
				auxi_num2 = aux_num_fun(head_tp2->next);
			}
			if (flags == 0)
				head_tmp1 = head_tmp1->next;
		}
		head_tmp1 = head_tmp1->next;
	}
}
/**
 * kind_sort - this sorts doubly linked list of ints
 * in asc order by using the Insertion sort algo
 * @list: points to list head
 * Return: nothing
 **/
void kind_sort(deck_node_t **list)
{
	deck_node_t *head_tp1, *head_tp2, *auxi1, *auxi2;
	int flags;

	if (list)
	{
		head_tp1 = *list;
		head_tp2 = *list;
		while (list && head_tp1->next)
		{
			if (head_tp1->next)
			{
				flags = 0;
				head_tp2 = head_tp1;
				while (head_tp2 && head_tp2->card->kind > head_tp2->next->card->kind)
				{
					auxi1 = head_tp2;
					auxi2 = head_tp2->next;
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
					head_tp2 = auxi2->prev;
					if (!auxi2->prev)
						*list = auxi2;
					flags = 1;
				}
			}
			if (flags == 0)
				head_tp1 = head_tp1->next;
		}
	}
}
/**
 * sort_deck - this sorts the deck of cards
 * @deck: the pointer to deck
 * Return: nothing
 *
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}
