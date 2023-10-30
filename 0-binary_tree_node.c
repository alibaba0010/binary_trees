#include "binary_trees.h"

/**
* binary_tree_node - Function to create a binary tree node
* @parent: pointer to the parent node
* @value: value to store in node
*
* Return: pointer to the binary tree node created
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}