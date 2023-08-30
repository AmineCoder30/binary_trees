#include "binary_trees.h"

/**
 * hg_rec - to get the height of our tree
 * @tree: our tree
 * Return: height
 */
size_t hg_rec(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	left = hg_rec(tree->left);
	right = hg_rec(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_height - calls hg_rec to return the height
 * of a binary tree
 *
 * @tree: our tree
 * Return: the height of our tree;
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (hg_rec(tree) - 1);
}
