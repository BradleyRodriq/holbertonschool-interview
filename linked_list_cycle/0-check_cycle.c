#include "lists.h"

/**
 * check_cycle - Checks if a linked list has a cycle.
 *
 * @list: Pointer to the HEAD NODE of a linked list.
 *
 * Return: 1 if there's a cycle in 'list',
 * 0 if there isn't.
 */
int check_cycle(listint_t *list)
{
	listint_t *list1 = list;
	listint_t *list2 = list;

	while (list1 && list2)
	{
		if (list1 == NULL)
			return (0);
		if (list2 == NULL)
			return (0);

		list1 = list1->next;

		list2 = list2->next;
		if (list2 == NULL)
			return (0);
		list2 = list2->next;

		if (list1 == list2)
			return (1);
	}

	return (0);
}
