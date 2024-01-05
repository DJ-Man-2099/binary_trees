#include "binary_trees.h"

/**
 * bst_search - search element in  binary search tree
 *
 * Return: the needed node
 *
 * @tree: the root node of binary tree
 *
 * @value: the needed value
 *
*/

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *cur;

	if (tree == NULL)
		return (NULL);
	cur = (bst_t *)tree;
	while (cur != NULL)
	{
		if (value > cur->n)
			cur = cur->right;
		else if (value < cur->n)
			cur = cur->left;
		else
			return (cur);
	}
	return (NULL);
}
