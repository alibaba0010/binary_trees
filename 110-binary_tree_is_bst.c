#include "binary_trees.h"
/**
 * check_sub_tree_Left: check if all nodes are smaller than
 * the root specified
 * @node: node in the tree to verify the condition
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int left_node = 0, right_node = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left_node = check_sub_tree_Left(node->left, max);
		right_node = check_sub_tree_Left(node->right, max);
		if (left_node == right_node && left_node == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_right - check if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify the condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int left_node = 0, right_node = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left_node = check_sub_tree_Right(node->left, min);
		right_node = check_sub_tree_Right(node->right, min);
		if (left_node == right_node && left_node == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - says if a tree is a binary
 * search tree or not
 * the process here first verify that the left_node node is smaller than the root
 * then verify if the right_node node is bigger than the root.
 * after that verify if the left_node subtree has nodes smaller than the root
 * and the right_node subtree has bigger nodes than root
 * @tree: node that point to the tree to check
 * Return: 1 if it is a BST else 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left_node = 2, right_node = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left_node = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right_node = binary_tree_is_bst(tree->right);
	}
	if (left_node != 2 || right_node != 2)
	{
		if (left_node == 0 || right_node == 0)
			return (0);
	}
	return (1);
}

