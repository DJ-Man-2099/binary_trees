#include "binary_trees.h"

/**
 * binary_tree_uncle - binary tree function
 *
 * finds the uncle of a node
 *
 * @node: a pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node
 * or NULL If node is NULL or has no uncle
 * or the parent is NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (node != NULL && node->parent != NULL &&
		node->parent->parent != NULL)
	{
		if (node->parent->parent->left != NULL &&
			node->parent->parent->left != node->parent)
		{
			uncle = node->parent->parent->left;
		}
		else if (node->parent->parent->right != NULL &&
				 node->parent->parent->right != node->parent)
		{
			uncle = node->parent->parent->right;
		}
	}

	return (uncle);
}
