#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to loop through
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
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
			length = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			row = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((length > row) ? length : row);
	}
}
/**
 * binary_tree_depth - depth of a specified node from the root
 * @tree: node to check the depth of the tree
 * Return: 0 if it is the root or else the number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node-this function makes a linked list from the depth level and node
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new_node, *aux;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = level;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new_node->next = NULL;
		aux->next = new_node;
	}
}
/**
 * recursion - loops through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of the linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}

