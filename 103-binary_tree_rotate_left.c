#include "binary_trees.h"

/**
 * binary_tree_rotate_left - func that performs
 * a left-rotation on a binary tree
 * @tree: our tree
 * Return: new root pointer
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *nw_rt;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	nw_rt = tree->right;

	if (nw_rt->left)
	{
		tree->right = nw_rt->left;
		nw_rt->left->parent = tree;
	}
	else
	{
		tree->right = NULL;
	}

	nw_rt->left = tree;
	nw_rt->parent = tree->parent;
	tree->parent = nw_rt;

	return (nw_rt);
}
