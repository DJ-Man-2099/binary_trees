#include "binary_trees.h"

void run_func(void (*func)(int), binary_tree_t *root, int cur);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - run function with the data of the node
 *
 * Return: void
 *
 * @tree: the root node of binary tree
 *
 * @func: the function to run on the node of the tree
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *root;
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	root = (binary_tree_t *)tree;
	for (i = 1; i <= height + 1; i++)
	{
		run_func(func, root, i);
	}

}

/**
 * run_func - run the function on the current node
 *
 * Return: void
 *
 * @func: the function to run
 *
 * @root: the root node to the tree
 *
 * @cur: the current need node
*/

void run_func(void (*func)(int), binary_tree_t *root, int cur)
{
	if (root == NULL)
		return;
	if (cur == 1)
		func(root->n);
	else if (cur > 1)
	{
		run_func(func, root->left, cur - 1);
		run_func(func, root->right, cur - 1);
	}
}

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
