#include "binary_trees.h"

/**
 * dp_rec - measr the depth of a node
 * @tree: our tree
 * Return: depth
 */
size_t dp_rec(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (dp_rec(tree->parent) + 1);
}

/**
 * binary_tree_depth - function that measures the depth of a
 *  node in a binary tree
 * @tree: our tree
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (dp_rec(tree));
}
