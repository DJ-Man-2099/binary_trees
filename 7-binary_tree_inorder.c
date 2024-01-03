#include "binary_trees.h"

/**
 * binary_tree_inorder - binary tree function
 *
 * goes through a binary tree using in-order traversal
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL &&
		func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
