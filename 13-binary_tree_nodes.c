#include "binary_trees.h"

/**
 * parent_br_tree - func that check if the node is
 * is parent
 * @node: pointer
 * Return: 1 or 0
 */
int parent_br_tree(const binary_tree_t *node)
{
	int prt = 0;

	if (node && (node->left || node->right))
		prt = 1;

	return (prt);
}

/**
 * binary_tree_nodes - function that counts the nodes with at least 1
 * child in a binary tree
 * @tree: our tree
 * Return: number of parent
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (parent_br_tree(tree))
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);

	return (0);
}
