#include "binary_trees.h"

/**
 * binary_tree_nodes - binary tree function
 *
 * counts the nodes with at least 1 child in a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the nodes
 *
 * Return: nodes of a binary tree
 * or 0 If tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree != NULL)
	{
		if (tree->left != NULL)
			nodes += binary_tree_nodes(tree->left);
		if (tree->right != NULL)
			nodes += binary_tree_nodes(tree->right);
		if (tree->left != NULL || tree->right != NULL)
			nodes++;
	}

	return (nodes);
}
