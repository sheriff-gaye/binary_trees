#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a node is a root
 * @node: node to check
 * Return: return 1 if node is root of 0 istead
 */

int binary_tree_is_root(const binary_tree_t *node)
{
    if (node != NULL && node->parent == NULL)
        return (1);
    else
        return (0);
}
