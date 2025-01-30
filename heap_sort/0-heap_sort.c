#include "sort.h"

/**
 * sift_down - Sifts down a node to maintain the max heap property
 * @array: The array representing the heap
 * @start: The index to start sifting down from
 * @end: The end index of the heap
 * @size: The original size of the array (for printing)
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
  size_t root = start;
  size_t child, swap_idx;
  int temp;

  while (2 * root + 1 <= end)
  {
    child = 2 * root + 1;
    swap_idx = root;

    if (array[child] > array[swap_idx])
      swap_idx = child;
    if (child + 1 <= end && array[child + 1] > array[swap_idx])
      swap_idx = child + 1;

    if (swap_idx == root)
      return;

    temp = array[root];
    array[root] = array[swap_idx];
    array[swap_idx] = temp;
    print_array(array, size);
    root = swap_idx;
  }
}
