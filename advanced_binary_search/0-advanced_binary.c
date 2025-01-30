#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);

/**
 * advanced_binary_helper - Recursive helper function to perform advanced binary search.
 * @array: Pointer to the first element of the array.
 * @low: Starting index of the subarray.
 * @high: Ending index of the subarray.
 * @value: Value to search for.
 *
 * Return: The index of the first occurrence of the value, or -1 if not found.
 */
static int advanced_binary_helper(int *array, int low, int high, int value)
{
  if (low > high)
  {
    return -1;
  }

  printf("Searching in array: ");
  for (int i = low; i <= high; ++i)
  {
    printf("%d", array[i]);
    if (i < high)
    {
      printf(", ");
    }
  }
  printf("\n");

  if (low == high)
  {
    return (array[low] == value) ? low : -1;
  }

  int mid = low + (high - low) / 2;

  if (array[mid] < value)
  {
    return advanced_binary_helper(array, mid + 1, high, value);
  }
  else
  {
    int left_result = advanced_binary_helper(array, low, mid, value);
    if (left_result != -1)
    {
      return left_result;
    }
    else if (array[mid] == value)
    {
      return mid;
    }
    else
    {
      return -1;
    }
  }
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index of the first occurrence of the value, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
  if (array == NULL || size == 0)
  {
    return -1;
  }
  return advanced_binary_helper(array, 0, size - 1, value);
}
