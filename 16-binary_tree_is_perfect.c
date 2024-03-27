
#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the depth.
 *
 * Return: The depth of the tree
 */
static int tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else
		return (tree_depth(tree->parent) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	int depth_left, depth_right;

	if (!tree)
		return (0);

	left = tree->left;
	right = tree->right;

	if (!left && !right)
		return (1);

	if (!left || !right)
		return (0);

	depth_left = tree_depth(left);
	depth_right = tree_depth(right);

	if (depth_left == depth_right)
		return (binary_tree_is_perfect(left) && binary_tree_is_perfect(right));

	return (0);
}
