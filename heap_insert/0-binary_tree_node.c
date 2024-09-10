#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of the new node
 * @value: value to store in the new node
 *
 * Return: address of created node if the malloc was successful,
 * NULL otherwise.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *result = malloc(sizeof(binary_tree_t));

	if (result == NULL)
		return (NULL);

	result->n = value;
	result->parent = parent;
	result->left = NULL;
	result->right = NULL;

	return (result);
}
