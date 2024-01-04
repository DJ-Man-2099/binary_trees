#include "binary_trees.h"

/**
 * b_is_leaf - binary tree function
 *
 * checks if a node is a leaf
 *
 * @node: a pointer to the node to check
 *
 * Return:  1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */

int b_is_leaf(const binary_tree_t *node)
{
	int is_leaf = 0;

	if (node != NULL &&
		node->left == NULL &&
		node->right == NULL)

		is_leaf = 1;

	return (is_leaf);
}

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
	int is_perfect = 0, is_perfect_left = 1,
		is_perfect_right = 1;

	if (tree != NULL)
	{
		if (tree->left != NULL)
			is_perfect_left = binary_tree_is_perfect(tree->left);
		if (tree->right != NULL)
			is_perfect_right = binary_tree_is_perfect(tree->right);
		if (is_perfect_left != 0 && is_perfect_right != 0 &&
			((tree->left != NULL && tree->right != NULL && b_is_leaf(tree) != 1) ||
			 (tree->left == NULL && tree->right == NULL && b_is_leaf(tree) == 1)) &&
			b_balance(tree) == 0)
		{
			is_perfect = 1;
		}
	}

	return (is_perfect);
}
