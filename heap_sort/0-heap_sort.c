#include "sort.h"

/* Declare sift_down as static (only visible in this file) */
static void sift_down(int *array, size_t start, size_t end, size_t size);

/**
 * sift_down - Maintains max heap property
 * @array: Array to sort
 * @start: Start index
 * @end: End index
 * @size: Original array size (for printing)
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
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

/**
 * heap_sort - Sorts an array using heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
  size_t end;
  int temp;
  int i;

  if (!array || size < 2)
    return;

  /* Build max heap */
  for (i = (size / 2) - 1; i >= 0; i--)
    sift_down(array, i, size - 1, size);

  end = size - 1;
  while (end > 0)
  {
    /* Swap root (max) with last element */
    temp = array[0];
    array[0] = array[end];
    array[end] = temp;
    print_array(array, size);
    end--;
    sift_down(array, 0, end, size);
  }
}
