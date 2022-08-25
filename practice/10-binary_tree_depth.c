#include "binary_trees.h"

/**
 * binary_tree_depth - postorder
 * @tree: node to check
 * Return: nothing
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
    unsigned int depth = 0;
    if (tree == NULL)
        return (0);
    while (tree->parent != NULL)
    {
        depth += 1;
        tree = tree->parent;
    }
    return (depth);
}
