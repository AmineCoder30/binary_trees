#include "binary_trees.h"

int prIsfull(const binary_tree_t *node);
int prIsfull(const binary_tree_t *node);
int isLeaf(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - function that checks if a
 * binary tree is perfect
 * @tree: tree root
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if (isLeaf(tree->left) && isLeaf(tree->right))
			return (1);

		if (prIsfull(tree))
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}
/**
 * prIsfull - checks if a node is a parent
 * @node: nd pointer
 * Return: 1 or 0
 */
int prIsfull(const binary_tree_t *node)
{
	int prt = 0;

	if (node && node->left && node->right)
		prt = 1;

	return (prt);
}

/**
 * isLeaf - checks if a node is a leaf
 * @node: nd pointer
 * Return: 1 or 0
 */
int isLeaf(const binary_tree_t *node)
{
	int lf = 0;

	if (node && !(node->left) && !(node->right))
		lf = 1;

	return (lf);
}

/**
 * height - measures the height of a tree
 * @tree: tree root
 * Return: height
 */
int height(const binary_tree_t *tree)
{
	int lf = 0;
	int rgt = 0;

	if (tree == NULL)
		return (-1);

	lf = height(tree->left);
	rgt = height(tree->right);

	if (lf > rgt)
		return (lf + 1);

	return (rgt + 1);
}

