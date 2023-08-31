#include "binary_trees.h"

size_t hg_rec(const binary_tree_t *tree);
size_t bnTrHeght(const binary_tree_t *tree);

/**
 * binary_tree_balance - calls recursive_balance to return the balance
 * of a binary tree
 *
 * @tree: tree root
 * Return: balance factor of the tree or 0 if tree is NULL;
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bnTrHeght(tree->left) - bnTrHeght(tree->right));
}

/**
 * bnTrHeght - calls hg_rec to return the height
 * of a binary tree
 *
 * @tree: our tree
 * Return: the height of our tree;
 */
size_t bnTrHeght(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (hg_rec(tree) - 1);
}

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





