#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_check_complete(tree, 0, binary_tree_count_nodes(tree)));
}

/**
 * binary_tree_check_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 * @index: The index of the current node
 * @count: The total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_check_complete(const binary_tree_t *tree,
		size_t index, size_t count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (binary_tree_check_complete(tree->left, 2 * index + 1, count) &&
			binary_tree_check_complete(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_count_nodes - Counts the number of nodes in a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The number of nodes in the tree
 */
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_count_nodes(tree->left) +
			binary_tree_count_nodes(tree->right));
}
