#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if no
 *         common ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor1 = first, *ancestor2 = second;

	while (ancestor1 != ancestor2)
	{
		ancestor1 = ancestor1 ? ancestor1->parent : second;
		ancestor2 = ancestor2 ? ancestor2->parent : first;
	}
	return ((binary_tree_t *)ancestor1);
}
