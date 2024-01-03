#include "binary_trees.h"

/**
 * binary_tree_height - binary tree function
 *
 * measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: height of a binary tree
 * or 0 If tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, other_height = 0;

	if (tree != NULL)
	{
		height = binary_tree_height(tree->left);
		if (tree->left != NULL)
			height++;
		other_height = binary_tree_height(tree->right);
		if (tree->right != NULL)
			other_height++;
		if (other_height > height)
			height = other_height;
	}

	return (height);
}
