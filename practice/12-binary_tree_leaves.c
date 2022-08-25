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
 * binary_tree_leaves - postorder
 * @tree: node to check
 * Return: nothing
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
    unsigned int right = 0, left = 0;
    if (tree == NULL)
        return (0);

    if (binary_tree_is_leaf(tree) == 1)
        return (1);

    left = binary_tree_leaves(tree->left);
    right = binary_tree_leaves(tree->right);

    return (left + right);
}
