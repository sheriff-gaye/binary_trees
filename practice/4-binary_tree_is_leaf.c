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
