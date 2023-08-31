#include "binary_trees.h"
/**
 * bnTRlf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int bnTRlf(const binary_tree_t *node)
{
	int lf = 0;

	if (node && !(node->left) && !(node->right))
		lf = 1;

	return (lf);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: our tree
 * Return: leaves's number
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (bnTRlf(tree))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
