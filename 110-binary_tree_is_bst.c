#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, NULL, NULL));
}

/**
 * is_bst_util - Utility function to check if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree to check
 * @min: A pointer to the minimum node that the current node can have
 * @max: A pointer to the maximum node that the current node can have
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) || (max != NULL && tree->n >= max->n))
		return (0);

	return (is_bst_util(tree->left, min, tree) &&
			is_bst_util(tree->right, tree, max));
}
