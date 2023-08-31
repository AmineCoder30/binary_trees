#include "binary_trees.h"

int isTRcmpl(const binary_tree_t *tree, int i, int cnds);
size_t bnTRsize(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - calls to tree_is_complete function
 * @tree: tree root
 * Return: 1 or O
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnds;

	if (tree == NULL)
		return (0);

	cnds = bnTRsize(tree);

	return (isTRcmpl(tree, 0, cnds));
}

/**
 * isTRcmpl - func that checks if tree is complete
 * @tree: tree pnter
 * @i: index
 * @cnds: node num
 * Return: 1 or 0
 */
int isTRcmpl(const binary_tree_t *tree, int i, int cnds)
{
	if (tree == NULL)
		return (1);

	if (i >= cnds)
		return (0);

	return (isTRcmpl(tree->left, (2 * i) + 1, cnds) &&
		isTRcmpl(tree->right, (2 * i) + 2, cnds));
}

/**
 * bnTRsize - funct that measures the size of a binary tree
 * @tree: tree root
 * Return: size of tree
 */
size_t bnTRsize(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bnTRsize(tree->left) + bnTRsize(tree->right) + 1);
}


