#include "binary_trees.h"

/**
 * binary_tree_rotate_left - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;

	if (new_root->left)
	{
		tree->right = new_root->left;
		new_root->left->parent = tree;
	}
	else
	{
		tree->right = NULL;
	}

	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
