#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth, left_depth, right_depth;

	if (!tree)
		return (0);

	left_depth = tree->left ? binary_tree_depth(tree->left) : 0;
	right_depth = tree->right ? binary_tree_depth(tree->right) : 0;

	if (left_depth != right_depth)
		return (0);

	depth = binary_tree_depth(tree);

	return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right) && left_depth == depth && right_depth == depth);
}
