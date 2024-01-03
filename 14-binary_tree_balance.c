#include "binary_trees.h"

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

	if (tree != NULL &&
		(tree->left != NULL ||
		 tree->right != NULL))
	{
		if (tree->left != NULL &&
			tree->right != NULL)
			balance = 2;
		else
			balance = -1;
	}

	return (balance);
}
