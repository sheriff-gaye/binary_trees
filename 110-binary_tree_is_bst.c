#include "binary_trees.h"

/**
 * binary_tree_is_bst - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (check_less_greater(tree->left, tree->n, 1) &&
		check_less_greater(tree->right, tree->n, 2))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * check_less_greater - verify if node is (less or greater) than root value
 * @tree: a pointer to the first node
 * @n: root value
 * @flag: switch to active lees or greater mode
 * Return: return 1 if are right or 0 if failes
 */
int check_less_greater(const binary_tree_t *tree, int n, int flag)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (flag == 1)
	{
		if (tree->n < n)
		{
			left = check_less_greater(tree->left, n, flag);
			right = check_less_greater(tree->right, n, flag);
			if (left != 0 && right != 0)
			{
				return (1);
			}
		}
	}
	if (flag == 2)
	{
		if (tree->n > n)
		{
			left = check_less_greater(tree->left, n, flag);
			right = check_less_greater(tree->right, n, flag);
			if (left != 0 && right != 0)
			{
				return (1);
			}
		}
	}
	return (0);
}
