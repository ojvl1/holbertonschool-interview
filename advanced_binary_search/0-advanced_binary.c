#include <stdio.h>

int advanced_binary(int *array, size_t size, int value);

static int advanced_binary_helper(int *array, int low, int high, int value)
{
  printf("Searching in array: ");
  for (int i = low; i <= high; i++)
  {
    printf("%d", array[i]);
    if (i < high)
    {
      printf(", ");
    }
  }
  printf("\n");

  if (low > high)
  {
    return -1;
  }

  int mid = (low + high) / 2;

  if (array[mid] < value)
  {
    return advanced_binary_helper(array, mid + 1, high, value);
  }
  else
  {
    if (array[mid] == value)
    {
      if (mid == low || array[mid - 1] < value)
      {
        return mid;
      }
      else
      {
        int left_result = advanced_binary_helper(array, low, mid - 1, value);
        return (left_result != -1) ? left_result : mid;
      }
    }
    else
    {
      return advanced_binary_helper(array, low, mid, value);
    }
  }
}

int advanced_binary(int *array, size_t size, int value)
{
  if (array == NULL || size == 0)
  {
    return -1;
  }
  return advanced_binary_helper(array, 0, size - 1, value);
}
