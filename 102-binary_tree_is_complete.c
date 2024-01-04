#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes);

/**
 * binary_tree_is_complete - check if binary tree is complete
 *
 * Return: 1 if completed
 *
 * @tree: a pointer to the root node of the tree
 *
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete - Recursive function to check if a binary tree is complete.
 * @tree: A pointer to the current node.
 * @index: The index of the current node.
 * @nodes: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
*/
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
		is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_size - binary tree function
 *
 * measures the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: size of a binary tree
 * or 0 If tree is NULL
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		size++;
	}

	return (size);
}
