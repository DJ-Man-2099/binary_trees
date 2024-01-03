#include "binary_trees.h"

/**
 * b_height - binary tree function
 *
 * measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: height of a binary tree
 * or 0 If tree is NULL
 */

size_t b_height(const binary_tree_t *tree)
{
	size_t height = 0, other_height = 0;

	if (tree != NULL)
	{
		height = b_height(tree->left);
		if (tree->left != NULL)
			height++;
		other_height = b_height(tree->right);
		if (tree->right != NULL)
			other_height++;
		if (other_height > height)
			height = other_height;
	}

	return (height);
}

/**
 * binary_tree_balance - binary tree function
 *
 * measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: nodes of a binary tree
 * or 0 If tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (tree != NULL)
	{
		if (tree->left != NULL)
			balance++;
		if (tree->right != NULL)
			balance--;
		balance += b_height(tree->left) - b_height(tree->right);
	}

	return (balance);
}
