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
	func(root->n);
	for (i = 0; i < height; i++)
	{
		run_func(func, root, i);
	}
	
}

void run_func(void (*func)(int), binary_tree_t *root, int cur)
{
	if (cur == 1)
		func(root->n);
	else if (cur > 1)
	{
		run_func(func, root->left, cur - 1);
		run_func(func, root->right, cur - 1);
	}
}

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
