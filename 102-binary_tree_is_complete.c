#include "binary_trees.h"

size_t sz_of_tree(const binary_tree_t *tree);
int is_cmpt(const binary_tree_t *tree, int i, int cnds);

/**
 * binary_is_cmpt - function that calls to is_cmpt function
 * @tree: our tree
 * Return: 1 or 0
 */
int binary_is_cmpt(const binary_tree_t *tree)
{
	size_t cnds;

	if (tree == NULL)
		return (0);

	cnds = sz_of_tree(tree);

	return (is_cmpt(tree, 0, cnds));
}

/**
 * is_cmpt - checks if tree is complete
 * @tree: tree pntr
 * @i: indx
 * @cnds: num of nodes
 * Return: 1 or 0
 */
int is_cmpt(const binary_tree_t *tree, int i, int cnds)
{
	if (tree == NULL)
		return (1);

	if (i >= cnds)
		return (0);

	return (is_cmpt(tree->left, (2 * i) + 1, cnds) &&
		is_cmpt(tree->right, (2 * i) + 2, cnds));
}

/**
 * sz_of_tree - measures the size of a binary tree
 * @tree: our tree
 * Return: tree size;
 */
size_t sz_of_tree(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (sz_of_tree(tree->left) + sz_of_tree(tree->right) + 1);
}


