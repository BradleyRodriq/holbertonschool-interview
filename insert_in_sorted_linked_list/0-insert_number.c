
#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts new node 
 *
 * @head: pointer to head pointer of linked list of integers
 * @number: number to put in new node
 *
 * Return: the address of the new node if the memory allocation
 * was successful, NULL otherwise.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = malloc(sizeof(listint_t));
	listint_t **current = head;

	/* memory failed */
	if (node == NULL)
		return (NULL);

	while (*current && (**current).n < number)
		current = &(**current).next;

	node->n = number;
	node->next = *current;

	*current = node;

	return (node);
}
