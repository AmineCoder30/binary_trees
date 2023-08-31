#include "binary_trees.h"

/**
 * binary_tree_rotate_right - func that performs a right-rotation
 * on a binary tree
 * @tree: our tree
 * Return: root pntr
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *nw__rt;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	nw__rt = tree->left;

	if (nw__rt->right)
	{
		tree->left = nw__rt->right;
		nw__rt->right->parent = tree;
	}
	else
	{
		tree->left = NULL;
	}

	nw__rt->right = tree;
	nw__rt->parent = tree->parent;
	tree->parent = nw__rt;

	return (nw__rt);
}
