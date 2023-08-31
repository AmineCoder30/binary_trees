#include "binary_trees.h"

size_t hgt_rec(const binary_tree_t *tree);
void lv_pr_func(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - prints data in level-order traversal
 * @tree: our tree
 * @func: function pointer
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height;
	size_t i;

	if (tree == NULL || func == NULL)
		return;

	height = hgt_rec(tree);

	for (i = 1; i <= height; i++)
		lv_pr_func(tree, i, func);
}

/**
 * lv_pr_func - prints nodes at the same level
 * @tree: tree root
 * @lv: level node
 * @func: pointer to a function
 * Return: no return
 */
void lv_pr_func(const binary_tree_t *tree, int lv, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (lv == 1)
		func(tree->n);
	else if (lv > 1)
	{
		lv_pr_func(tree->left, lv - 1, func);
		lv_pr_func(tree->right, lv - 1, func);
	}
}
/**
 * hgt_rec - measures the height of a binary tree
 * @tree: our tree
 * Return: return the height
 */
size_t hgt_rec(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	left = hgt_rec(tree->left);
	right = hgt_rec(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}


