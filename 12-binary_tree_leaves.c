#include "binary_trees.h"
/**
 * binary_tree_leaves - function that returns the number of leaves in a tree
 * @tree: tree to check
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, length = 0, row = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		length = binary_tree_leaves(tree->left);
		row = binary_tree_leaves(tree->right);
		leaf = length + row;
		return ((!length && !row) ? leaf + 1 : leaf + 0);
	}
}