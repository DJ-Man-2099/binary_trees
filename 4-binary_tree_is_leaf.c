#include "binary_trees.h"

/**
 * binary_tree_is_leaf - binary tree function
 *
 * checks if a node is a leaf
 *
 * @node: a pointer to the node to check
 *
 * Return:  1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	int is_leaf = 0;

	if (node != NULL &&
		node->left == NULL &&
		node->right == NULL)

		is_leaf = 1;

	return (is_leaf);
}
