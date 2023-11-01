#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that rotate left of the binary tree.
 * @tree: The root node of the tree
 * Return: Pointer node to the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	aux = tree->right;
	tree->right = aux->left;
	if (aux->left != NULL)
	{
		aux->left->parent = tree;
	}
	aux->left = tree;
	aux->parent = tree->parent;
	tree->parent = aux;
	return (aux);
}

