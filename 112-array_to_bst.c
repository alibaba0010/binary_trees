#include "binary_trees.h"
/**
 * array_to_bst - turns an array to a BST
 * @array: array to turns to BST
 * @size: size of array
 * Return: BST from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t len = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; len < size; len++)
	{
		if (len == 0)
		{
			bst_insert(&root, array[len]);
		}
		else
		{
			bst_insert(&root, array[len]);
		}
	}
	return (root);
}

