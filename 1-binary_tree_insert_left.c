#include "binary_trees.h"

/**
 * binary_tree_insert_left - binary tree function
 *
 * inserts a node as the left-child of another node
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node
 *
 * @parent: a pointer to the node to insert the left-child in
 * @value: value to put in the new node
 *
 * Return: a pointer to the new node
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent != NULL)
	{
		node = calloc(sizeof(binary_tree_t), 1);
		if (node != NULL && parent != NULL)
		{
			node->parent = parent;
			node->n = value;
			if (parent->left != NULL)
			{
				node->left = parent->left;
				parent->left->parent = node;
			}
			parent->left = node;
		}
	}
	return (node);
}
