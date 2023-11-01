#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree
 * @tree: tree to loop through
 * Return: the height of the tree
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t length = 0;
	size_t row = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			length = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			row = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((length > row) ? length : row);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right_node = 0, left_node = 0, total = 0;

	if (tree)
	{
		left_node = ((int)binary_tree_height_b(tree->left));
		right_node = ((int)binary_tree_height_b(tree->right));
		total = left_node - right_node;
	}
	return (total);
}
