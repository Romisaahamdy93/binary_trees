#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);  // Call the provided function for the current node

    // Recursively traverse the left and right subtrees
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}
