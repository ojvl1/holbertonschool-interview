#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: Maximum value
 */
int max(int a, int b)
{
return (a > b ? a : b);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree, or 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
if (!tree)
{
return (0);
}
return (1 + max(binary_tree_height(tree->left),
binary_tree_height(tree->right)));
}

/**
 * binary_tree_is_bst - Checks if a tree is a valid BST
 * @tree: Pointer to the root node
 * @min: Minimum value allowed
 * @max: Maximum value allowed
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
if (!tree)
return (1);
if (tree->n <= min || tree->n >= max)
{
return (0);
}
return (binary_tree_is_bst(tree->left, min, tree->n) &&
binary_tree_is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_balance_factor - Measures the balance factor of a node
 * @tree: Pointer to the node
 * Return: Balance factor
 */
int binary_tree_balance_factor(const binary_tree_t *tree)
{
if (!tree)
{
return (0);
}
return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (!tree)
return (0);
if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
return (0);
if (abs(binary_tree_balance_factor(tree)) > 1)
return (0);
if (tree && !tree->left && !tree->right)
return (1);
return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
