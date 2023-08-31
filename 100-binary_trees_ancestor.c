#include "binary_trees.h"


size_t depth_tr(const binary_tree_t *tree);
size_t hg_rec(const binary_tree_t *tree);
/**
 * binary_tree_uncle - function thatfinds the lowest
 * common ancestor of two nodes
 * @first: ptr to the node num 1
 * @second: ptr to the node num 2
 * Return: pointer
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (depth_tr(first) > depth_tr(second))
		return (binary_trees_ancestor(first->parent, second));

	if (depth_tr(first) < depth_tr(second))
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}

/**
 * hg_rec - measures the depth of a node in a binary tree
 * @tree: our tree
 * Return: depth of our tree;
 */
size_t hg_rec(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (hg_rec(tree->parent) + 1);
}

/**
 * depth_tr - funct that calls hg_rec to return the depth
 * @tree: our tree
 * Return: depth of our tree;
 */
size_t depth_tr(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (hg_rec(tree));
}


