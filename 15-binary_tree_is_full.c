#include "binary_trees.h"

/**
 * node_is_balanced - binary tree function
 *
 * checks if a binary tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if full
 * or 0 If tree is NULL
 */

int node_is_balanced(const binary_tree_t *tree)
{
	int is_full = 0;

	if (tree != NULL)
	{
		if ((tree->left == NULL && tree->right == NULL) ||
			(tree->left != NULL && tree->right != NULL))
		{
			is_full = 1;
		}
	}

	return (is_full);
}

/**
 * binary_tree_is_full - binary tree function
 *
 * checks if a binary tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if full
 * or 0 If tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 0;

	if (tree != NULL)
	{
		is_full = 1;
		is_full = binary_tree_is_full(tree->left);
		if (is_full != 0 || tree->left == NULL)
		{
			is_full = 1;
			is_full = binary_tree_is_full(tree->right);
			if (is_full != 0 || tree->right == NULL)
			{
				is_full = node_is_balanced(tree);
			}
		}
	}

	return (is_full);
}
