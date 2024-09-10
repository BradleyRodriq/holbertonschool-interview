#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * heapify_up - Restores the Max Heap property by moving a node up
 * @node: Pointer to the node to heapify
 *
 * Return: Pointer to the node in its final position
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *parent;
	int temp;

	if (!node || !node->parent)
		return (node);

	parent = node->parent;
	if (node->n > parent->n)
	{
		/* Swap the values */
		temp = node->n;
		node->n = parent->n;
		parent->n = temp;

		return (heapify_up(parent)); /* Continue heapifying up */
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current;
	heap_t **queue[1024]; /* Array for breadth-first search */
	int front = 0, back = 0;

	if (root == NULL)
		return (NULL);

	/* If the root is NULL, create a new root */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* BFS to find the first available position */
	queue[back++] = root; /* Enqueue the root */
	while (front < back)
	{
		current = *queue[front++]; /* Dequeue */

		/* Check if left child exists, else insert */
		if (current->left == NULL)
		{
			new_node = binary_tree_node(current, value);
			current->left = new_node;
			return (heapify_up(new_node));
		}
		else
		{
			queue[back++] = &current->left; /* Enqueue left child */
		}

		/* Check if right child exists, else insert */
		if (current->right == NULL)
		{
			new_node = binary_tree_node(current, value);
			current->right = new_node;
			return (heapify_up(new_node));
		}
		else
		{
			queue[back++] = &current->right; /* Enqueue right child */
		}
	}

	return (NULL); /* Shouldn't happen if the heap is valid */
}