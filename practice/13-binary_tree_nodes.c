#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a node is a leaf
 * @node: node to check
 * Return: return 1 if node is leaf of 0 istead
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node != NULL && node->left == NULL && node->right == NULL)
        return (1);
    else
        return (0);
}

/**
 * binary_tree_nodes - postorder
 * @tree: node to check
 * Return: nothing
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    unsigned int right = 0, left = 0;
	if (tree == NULL || binary_tree_is_leaf(tree) == 1)
		return (0);


    left = binary_tree_nodes(tree->left);
    right = binary_tree_nodes(tree->right);

    return (1 + left + right);
}
