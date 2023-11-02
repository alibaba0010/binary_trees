#include "binary_trees.h"
/**
 * aux_sort - create a tree using the half 
 * of the element of an array
 * @parent: parent of the node to create
 * @array: sorted array
 * @start: position where the array starts
 * @end: position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, start, mid - 1);
		root->right = aux_sort(root, array, mid + 1, end);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create an AVL tree from a sorted array
 * @array: sorted array
 * @size: size of the array
 * Return: AVL tree from the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

