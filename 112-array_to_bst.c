#include "binary_trees.h"

/**
 * array_to_bst - insert a new node in a Binary Search Tree
 * @array: arrya to use
 * @size: array size
 *
 * Return: If no common ancestor was found return NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *new_node = NULL;

	unsigned int index;

	for (index = 0; index < size; index++)
	{
		bst_insert(&new_node, array[index]);
	}
	return (new_node);
}
