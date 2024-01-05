#include "binary_trees.h"

/**
 * min_value_node - get the minmum value node
 *
 * Return: pointer to the node
 *
 * @node: the node to return its min value
*/

bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - remove node from bst
 *
 * Return: pointer to root
 *
 * @root: the root of bst
 *
 * @value: the value to remove
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = min_value_node(root->right);

		root->n = temp->n;

		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

