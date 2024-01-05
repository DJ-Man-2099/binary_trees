#include "binary_trees.h"

/**
 * array_to_bst - change array into binary search tree
 *
 * Return: pointer to the root node
 *
 * @array: the array to take elements from
 *
 * @size: the size of the array
 *
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;

	if (array == NULL)
		return (NULL);
	while (size)
	{
		bst_insert(&tree, *array);
		array++;
		size--;
	}
	return (tree);
}
