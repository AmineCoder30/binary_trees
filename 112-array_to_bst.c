#include "binary_trees.h"

/**
 * array_to_bst - function that builds a binary
 * search tree from an array
 * @array: first ele point
 * @size: size of array
 * Return: pntr
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t k;

	tree = NULL;

	for (k = 0; k < size; k++)
	{
		bst_insert(&tree, array[k]);
	}

	if (k == size)
		return (tree);

	return (NULL);
}
