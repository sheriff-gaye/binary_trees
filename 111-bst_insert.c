#include "binary_trees.h"

/**
 * bst_insert - insert a new node in a Binary Search Tree
 * @tree: a pointer to the first node
 * @value: int value
 *
 * Return: If no common ancestor was found return NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (tree != NULL)
	{
		if (*tree == NULL)
		{
			*tree = binary_tree_node(NULL, value);
			return (*tree);
		}
		tmp = *tree;
		while (tmp)
		{
			if (tmp->n == value)
			{
				break;
			}
			if (tmp->n > value)
			{
				if (tmp->left == NULL)
				{
					tmp->left = binary_tree_node(tmp, value);
					return (tmp->left);
				}
				tmp = tmp->left;
			}
			if (tmp->n < value)
			{
				if (tmp->right == NULL)
				{
					tmp->right = binary_tree_node(tmp, value);
					return (tmp->right);
				}
				tmp = tmp->right;
			}
		}
	}
	return (NULL);
}
