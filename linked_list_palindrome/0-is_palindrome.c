#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */

int _is_palindrome(listint_t ***head, listint_t **tail)
{
	if (*tail)
	{
		int inner_result = _is_palindrome(head, &((*tail)->next));

		int result = inner_result && (**head)->n == (*tail)->n;

		*head = &((**head)->next);

		return (result);
	}
	return (1);
}

/** 
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	return (_is_palindrome(&head, head));
}
