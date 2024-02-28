#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
/* If tree is NULL, it is not full */
if (tree == NULL)
return (0);
/* If a non-leaf node has only one child, it is not full */
if ((tree->left == NULL && tree->right != NULL) ||
(tree->left != NULL && tree->right == NULL))
return (0);
/* If a leaf node, it is full by definition */
if (tree->left == NULL && tree->right == NULL)
return (1);
/* Recursively check both left and right subtrees */
return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
