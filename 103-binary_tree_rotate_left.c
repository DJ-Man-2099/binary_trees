#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate binary tree left
 *
 * Return: pointer to the root of the function
 *
 * @tree: a pointer to the root node of the tree
 *
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	new_root->left = tree;

	return (new_root);
}

