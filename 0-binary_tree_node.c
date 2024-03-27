#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_binary_tree_node - Allocates and initializes a new binary tree node
 * @parent: A pointer to the parent node of the node being created
 * @value: The value to assign to the new node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *create_binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
	{
		return (NULL); /* Memory allocation failed */
	}

	/* Initialize the new node */
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node); /* Return the pointer to the new node */
}
