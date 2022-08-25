#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree at a given node.
 * @tree: The ponter to the node.
 *
 * Return: 0 if tree is null
 *         Otherwise the height of the tree.
 */
int height(binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	left = 1 + height(tree->left);
	right = 1 + height(tree->right);

	if (left > right)
		return (left);
	return (right);
}

/**
 * current_level - Prints all the nodes at a given level.
 * @tree: The pointer to the node.
 * @func: The pointer to the function to print the node.
 * @level: The level to print the nodes.
 *
 * Return: always void.
 */
void current_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree || !func)
		return;

	if (level == 1)
		func(tree->n);

	current_level(tree->left, func, level - 1);
	current_level(tree->right, func, level - 1);
}

/**
 * binary_tree_levelorder - Prints all the levels of a given tree.
 * @tree: The pointer to the root.
 * @func: The pointer to the function to print a node.
 *
 * Return: always void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level = 1, max;

	if (!tree || !func)
		return;

	max = height((binary_tree_t *)tree);

	while (level <= max)
		current_level(tree, func, level++);
}
