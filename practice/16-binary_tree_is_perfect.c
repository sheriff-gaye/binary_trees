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
 * binary_tree_height - get height
 * @tree: node to check
 * Return: nothing
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
    unsigned int left, right;
    if (tree == NULL || binary_tree_is_leaf(tree))
        return (0);
    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);
    if (left > right)
        return (1 + left);
    else
        return (1 + right);
}

/**
 * binary_tree_is_perfect - get height
 * @tree: node to check
 * Return: nothing
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    binary_tree_t *left, *right;
    if (tree == NULL)
        return (0);
    left = tree->left;
    right = tree->right;
    if (binary_tree_is_leaf(tree))
        return (1);
    if (left == NULL || right == NULL)
        return (0);

    if (binary_tree_height(left) == binary_tree_height(right))
    {
        if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
        {
            return (1);
        }
    }

    return (0);
}
