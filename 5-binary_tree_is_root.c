#include "binary_trees.h"

/**
 * binary_tree_is_root - binary tree function
 *
 * checks if a given node is a root
 *
 * @node: a pointer to the node to check
 *
 * Return:  1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	int is_root = 0;

	if (node != NULL &&
		node->parent == NULL)

		is_root = 1;

	return (is_root);
}
