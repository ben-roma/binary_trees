#include "binary_trees.h"

/**
 * depth - Measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: The depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree)
	{
		d++;
		tree = tree->parent;
	}
	return (d);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t d1 = depth(first), d2 = depth(second);

	/* Align first and second at the same depth */
	while (d1 > d2)
	{
		first = first->parent;
		d1--;
	}
	while (d2 > d1)
	{
		second = second->parent;
		d2--;
	}

	/* Move up the tree until we find the common ancestor */
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((first && second) ? (binary_tree_t *)first : NULL);
}
