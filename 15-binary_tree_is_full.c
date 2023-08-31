#include "binary_trees.h"

int trIsLeaf(const binary_tree_t *node);
int prFull(const binary_tree_t *node);

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: tree root
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (trIsLeaf(tree))
		return (1);

	if (prFull(tree))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

/**
 * prFull - checks if a node is a parent
 * @node: pntr of node
 * Return: 1 or 0
 */
int prFull(const binary_tree_t *node)
{
	int prt = 0;

	if (node && node->left && node->right)
		prt = 1;

	return (prt);
}

/**
 * trIsLeaf - checks if a node is a leaf
 * @node: pntr of node
 * Return: 1 or 0
 */
int trIsLeaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;

	return (leaf);
}