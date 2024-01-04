#include "binary_trees.h"

/**
 * binary_tree_sibling - binary tree function
 *
 * finds the sibling of a node
 *
 * @node: a pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node
 * or NULL If node is NULL or has no sibling
 * or the parent is NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (node != NULL && node->parent != NULL)
	{
		if (node->parent->left != NULL && node->parent->left != node)
		{
			sibling = node->parent->left;
		}
		else if (node->parent->right != NULL && node->parent->right != node)
		{
			sibling = node->parent->right;
		}
	}

	return (sibling);
}
