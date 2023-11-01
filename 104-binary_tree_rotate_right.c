#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the tree
 * Return: Pointer node to the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	aux = tree->left;
	tree->left = aux->right;
	if (aux->right != NULL)
	{
		aux->right->parent = tree;
	}
	aux->right = tree;
	aux->parent = tree->parent;
	tree->parent = aux;
	return (aux);
}

