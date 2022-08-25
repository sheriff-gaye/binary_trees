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
 * binary_tree_is_full - get height
 * @tree: node to check
 * Return: nothing
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
    unsigned int left, right;
    if (tree == NULL)
        return (0);
    if (binary_tree_is_leaf(tree))
        return (1);
    left = binary_tree_is_full(tree->left);
    right = binary_tree_is_full(tree->right);

    if (left == 0 || right == 0)
        return (0);

    return (1);
}
