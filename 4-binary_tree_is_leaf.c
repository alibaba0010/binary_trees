#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a node is leaf
 * @node: the node to check *
 * Return: 1 if node is leaf 1 otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}	
