#include "sort.h"

/**
 * insertion_sort_list - perform insertion sort on a doubly linked list.
 * @list: pointer to the address of the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *usptr, *temp;

	if (!list || !(*list)->next)
		return;

	usptr = (*list)->next;

	while (usptr)
	{
		curr = usptr->prev;
		temp = usptr->next;
		while (curr && usptr->n < curr->n)
		{
			curr->next = usptr->next;
			if (usptr->next)
				usptr->next->prev = curr;
			usptr->prev = curr->prev;
			usptr->next = curr;
			if (!curr->prev)
				*list = usptr;
			else
				curr->prev->next = usptr;
			curr->prev = usptr;
			curr = usptr->prev;
			print_list(*list);
		}
		usptr = temp;
	}
}
