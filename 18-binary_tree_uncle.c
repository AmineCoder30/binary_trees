#include "binary_trees.h"

binary_tree_t *SiblbnTR(binary_tree_t *node);

/**
 * binary_tree_uncle - func that find the uncle of node
 * @node: our node
 * Return: pointer
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (SiblbnTR(node->parent));
}

/**
 * SiblbnTR - funct that find the sibling of node
 * @node: node
 * Return: pointer
 */
binary_tree_t *SiblbnTR(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left != node)
		return (node->parent->left);

	return (node->parent->right);
}
