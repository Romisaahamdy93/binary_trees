#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the depth
 *
 * Return: Depth of the tree, or 0 if tree is NULL
 */
size_t depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree != NULL)
{
depth++;
tree = tree->parent;
}

return depth;
}

/**
 * is_leaf - Checks if a node is a leaf in a binary tree
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
unsigned char is_leaf(const binary_tree_t *node)
{
return (node != NULL && node->left == NULL && node->right == NULL);
}

/**
 * is_perfect_recursive - Recursive helper function
 * @tree: Pointer to the root node of the tree to check
 * @leaf_depth: Depth of the first leaf encountered
 * @level: Current level in the recursion
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth, size_t level)
{
if (tree == NULL)
return (1);

if (is_leaf(tree))
{
return (leaf_depth == level);
}

if (tree->left == NULL || tree->right == NULL)
{
return 0;
}

return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
        is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t leaf_depth;

if (tree == NULL)
return (0);

leaf_depth = depth(get_leaf(tree));
return is_perfect_recursive(tree, leaf_depth, 0);
}

/**
 * get_leaf - Finds the first leaf node in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the first leaf node, or NULL if tree is NULL
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
if (tree == NULL)
return NULL;

while (tree->left != NULL || tree->right != NULL)
{
if (tree->left != NULL)
tree = tree->left;
else
tree = tree->right;
}

return tree;
}

