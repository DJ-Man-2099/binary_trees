#include "binary_trees.h"

/**
 * binary_tree_node - binary tree function
 *
 * creates a binary tree node
 *
 * @parent: a pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: a pointer to the new node
 * or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = calloc(sizeof(binary_tree_t), 1);

	if (node != NULL)
	{
		node->parent = parent;
		node->n = value;
	}
	return (node);
}
