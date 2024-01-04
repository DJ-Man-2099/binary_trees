#include "binary_trees.h"

int check_bst(const binary_tree_t *root, int *prev);

/**
 * binary_tree_is_bst - check if binary tree is binary search tree
 *
 * Return: 1 if binary search tree
 *
 * @tree: the root node of binary tree
 *
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev;

	if (tree == NULL)
		return (0);
	prev = -99;

	return (check_bst(tree, &prev));
}

/**
 * check_bst - the recursive function to check the binary search tree
 *
 * Return: 1 if binary search tree
 *
 * @root: the node to check
 *
 * @prev: the value to compare with
*/

int check_bst(const binary_tree_t *root, int *prev)
{
	if (root == NULL)
		return (1);

	if (!check_bst(root->left, prev))
		return (0);

	if (root->n <= *prev)
	{
		return (0);
	}
	*prev = root->n;
	return (check_bst(root->right, prev));
}
