#include "binary_trees.h"

/**
 * binary_tree_size - postorder
 * @tree: node to check
 * Return: nothing
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
    unsigned int left = 0, right = 0;
    if (tree == NULL)
        return(0);
    
    right = binary_tree_size(tree->left);
    left = binary_tree_size(tree->right);
    
    return (1 + left + right);
}
