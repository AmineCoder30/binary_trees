#include "binary_trees.h"



/**
 * binary_tree_is_bst - funct that
 * calls to bst__check to check if tree is BST
 * @tree: our tree
 * Return: 1 or O
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst__check(tree));
}

/**
 * bst__check - funct to checks if binary
 * tree is a BST
 * @tree: our tree
 * Return: 1 or O
 */
int bst__check(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (isLeaf(tree))
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	if (!pr__checkt(tree->left) || !pr__checkt(tree->right))
		return (0);

	return (bst__check(tree->left) && bst__check(tree->right));
}
/**
 * isLeaf - funct to checks if a node
 * is a leaf
 * @node: pntr
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
 * pr__checkt - funct to checks if node has a lower/higher
 * than its grand parent
 * @tree: our tree
 * Return: 1 or 0
 */
int pr__checkt(const binary_tree_t *tree)
{
	const binary_tree_t *thePr;
	const binary_tree_t *gr__prt;

	if (tree == NULL || tree->parent == NULL || tree->parent->parent == NULL)
		return (1);

	thePr = tree->parent;
	gr__prt = thePr->parent;

	while (thePr && gr__prt)
	{
		if (thePr->n < gr__prt->n && tree->n >= gr__prt->n)
			return (0);

		if (thePr->n > gr__prt->n && tree->n <= gr__prt->n)
			return (0);

		thePr = thePr->parent;
		gr__prt = thePr->parent;
	}

	return (1);
}




