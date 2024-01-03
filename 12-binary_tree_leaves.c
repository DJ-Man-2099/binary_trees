#include "binary_trees.h"

/**
 * binary_tree_leaves - binary tree function
 *
 * measures the leaves of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the leaves
 *
 * Return: leaves of a binary tree
 * or 0 If tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree != NULL)
	{
		if (tree->left != NULL)
			leaves += binary_tree_leaves(tree->left);
		if (tree->right != NULL)
			leaves += binary_tree_leaves(tree->right);
		if (tree->left == NULL && tree->right == NULL)
			leaves++;
	}

	return (leaves);
}
