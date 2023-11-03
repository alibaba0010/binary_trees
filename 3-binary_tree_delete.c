#include "binary_trees.h"

/**
 * binary_tree_delete - free an entire tree using recursion it frees the node
 * when the node's left and right are NULL
 * @tree: tree to free
 * Return: Nothing if it fails
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree != NULL)
    {
        binary_tree_delete(tree->left);
        binary_tree_delete(tree->right);
        free(tree);
    }
}
