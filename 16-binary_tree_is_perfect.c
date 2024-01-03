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
 * b_balance - binary tree function
 *
 * measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: nodes of a binary tree
 * or 0 If tree is NULL
 */

int b_balance(const binary_tree_t *tree)
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
 * b_is_full - binary tree function
 *
 * checks if a binary tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if full
 * or 0 If tree is NULL
 */

int b_is_full(const binary_tree_t *tree)
{
	int is_full = 0;

	if (tree != NULL)
	{
		is_full = 1;
		is_full = b_is_full(tree->left);
		if (is_full != 0 || tree->left == NULL)
		{
			is_full = 1;
			is_full = b_is_full(tree->right);
			if (is_full != 0 || tree->right == NULL)
			{
				is_full = node_is_balanced(tree);
			}
		}
	}

	return (is_full);
}
/**
 * binary_tree_is_perfect - binary tree function
 *
 * checks if a binary tree is prefect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if perfect
 * or 0 If tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 0;

	if (tree != NULL)
	{
		if (b_is_full(tree) == 1 &&
			b_balance(tree) == 0)
		{
			is_perfect = 1;
		}
	}

	return (is_perfect);
}
