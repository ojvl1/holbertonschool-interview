#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tree - Recursively prints a binary tree
 * @tree: Pointer to the root node
 * @space: Space count for indentation
 */
void print_tree(const binary_tree_t *tree, int space)
{
    int i;
    if (!tree)
        return;

    space += 6;
    print_tree(tree->right, space);
    printf("\n");
    for (i = 6; i < space; i++)
        printf(" ");
    printf("(%d)\n", tree->n);
    print_tree(tree->left, space);
}

/**
 * binary_tree_print - Prints a binary tree visually
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;
    print_tree(tree, 0);
}
