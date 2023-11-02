#include "binary_trees.h"

/**
 * count_heap_nodes - Counts the number of node 
 * inside a tree
 * @root: Pointer to tree root node
 *
 * Return: Number of tree node
 */
int count_heap_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_heap_nodes(root->left) +
		    count_heap_nodes(root->right));
}


/**
 * bubble_down - Puts a node value in the correct 
 * position in the heap
 * @parent: Pointer to heap node
 */
void bubble_down(heap_t *parent)
{
	int node;
	heap_t *max_child = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		max_child = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			max_child = parent->right;

		if (max_child->n > parent->n)
		{
			node = parent->n;
			parent->n = max_child->n;
			max_child->n = node;
		}

		parent = max_child;
	}
}


/**
 * get_parent - Finds the parent node
 * @root: Pointer to heap node
 * @index: Index of the current node
 * @pind: Index being searched
 *
 * Return: Pointer to heap node
 */
heap_t *get_parent(heap_t *root, int index, int pind)
{
	heap_t *left_node = NULL, *right_node = NULL;

	if (!root || index > pind)
		return (NULL);

	if (index == pind)
		return (root);

	left_node = get_parent(root->left, index * 2 + 1, pind);
	if (left_node)
		return (left_node);

	right_node = get_parent(root->right, index * 2 + 2, pind);
	if (right_node)
		return (right_node);

	return (NULL);
}


/**
 * remove_last_node - Removes the last node of a heap
 * @root: Doublepointer to heap's root node
 * @parent: Pointer to parent node from which to remove the last node
 */
void remove_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	bubble_down(*root);
}


/**
 * heap_extract - Extracts the max value of a heap
 * @root: Double pointer to heap's root node
 *
 * Return: Heap's max value
 */
int heap_extract(heap_t **root)
{
	int node, pind = 0, max_value = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	max_value = (*root)->n;
	node = count_heap_nodes(*root);

	pind = (node - 2) / 2;
	parent = get_parent(*root, 0, pind);

	remove_last_node(root, parent);

	return (max_value);
}
