#include "binary_trees.h"
/**
 * binary_tree_inorder - print elements of the tree using in-order traversal
 * @tree: tree to loop through
 * @func: function to check node
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}