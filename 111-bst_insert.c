#include "binary_trees.h"

/**
 * bst_insert - insert node in bst
 *
 * Return: pointer to the added node
 *
 * @tree: a pointer to the root node of the tree
 *
 * @value: the needed value to add
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur, *needed, *new_node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	cur = *tree;
	while (cur != NULL)
	{
		needed = cur;
		if (value > cur->n)
			cur = cur->right;
		else if (value < cur->n)
			cur = cur->left;
		else
			return (NULL);
	}

	new_node = binary_tree_node(needed, value);
	if (value < needed->n)
		needed->left = new_node;
	else
		needed->right = new_node;
	return (new_node);
}
