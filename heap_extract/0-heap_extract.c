#include "binary_trees.h"

int count_nodes(heap_t *root);
heap_t *get_last_node(heap_t *root);
void heapify_down(heap_t *root);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
  heap_t *heap_root, *last_node;
  int value;

  if (root == NULL || *root == NULL)
    return (0);

  heap_root = *root;
  last_node = get_last_node(heap_root);

  value = heap_root->n;

  if (heap_root == last_node)
  {
    free(heap_root);
    *root = NULL;
    return (value);
  }

  heap_root->n = last_node->n;

  if (last_node->parent->left == last_node)
    last_node->parent->left = NULL;
  else
    last_node->parent->right = NULL;

  free(last_node);

  heapify_down(heap_root);

  return (value);
}

/**
 * count_nodes - Counts the number of nodes in a binary tree.
 * @root: A pointer to the root node of the tree.
 * Return: The number of nodes.
 */
int count_nodes(heap_t *root)
{
  if (root == NULL)
    return (0);
  return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_last_node - Finds the last node in a Max Binary Heap using binary path.
 * @root: A pointer to the root node of the heap.
 * Return: A pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
  int count = count_nodes(root);
  int mask;
  heap_t *node = root;

  if (count == 0)
    return (NULL);

  for (mask = 1; mask <= count; mask <<= 1)
    ;
  mask >>= 2;

  while (mask > 0)
  {
    if (count & mask)
      node = node->right;
    else
      node = node->left;
    mask >>= 1;
  }

  return (node);
}

/**
 * heapify_down - Restores the max-heap property by sifting down the root node.
 * @root: A pointer to the root node of the heap.
 */
void heapify_down(heap_t *root)
{
  heap_t *max = root;
  heap_t *left = root->left;
  heap_t *right = root->right;

  if (left && left->n > max->n)
    max = left;
  if (right && right->n > max->n)
    max = right;

  if (max != root)
  {
    int temp = root->n;

    root->n = max->n;
    max->n = temp;
    heapify_down(max);
  }
}
