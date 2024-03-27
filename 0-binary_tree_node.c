#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Allocates and initializes a new binary tree node
 * @parent: A pointer to the parent node of the node being created
 * @value: The value to assign to the new node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL); /* Memory allocation failed */
	
	/* Initialize the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node); /* Return the pointer to the new node */
}
