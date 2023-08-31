#include "binary_trees.h"

bst_t *insert_helper(bst_t **tr, int vl);

/**
 * bst_insert - funct that inserts a value
 * in a Binary Search Tree
 * @tree: our tree
 * @value: nd vl
 * Return: node ptr
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (insert_helper(tree, value));
}

/**
 * insert_helper - checks if node is inserted
 * @tr: our tree
 * @vl: nd vl
 * Return: node ptr
 */
bst_t *insert_helper(bst_t **tr, int vl)
{
	if (vl < (*tr)->n)
	{
		if ((*tr)->left == NULL)
		{
			(*tr)->left = binary_tree_node(*tr, vl);
			return ((*tr)->left);
		}
		else
		{
			return (insert_helper(&((*tr)->left), vl));
		}
	}

	if (vl > (*tr)->n)
	{
		if ((*tr)->right == NULL)
		{
			(*tr)->right = binary_tree_node(*tr, vl);
			return ((*tr)->right);
		}
		else
		{
			return (insert_helper(&((*tr)->right), vl));
		}
	}

	return (NULL);
}
