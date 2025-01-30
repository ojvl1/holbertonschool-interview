/**
 * heap_sort - Sorts an array using the heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
  size_t end;
  int i, temp;

  if (array == NULL || size < 2)
    return;

  for (i = (size / 2) - 1; i >= 0; i--)
    sift_down(array, i, size - 1, size);

  end = size - 1;
  while (end > 0)
  {
    temp = array[0];
    array[0] = array[end];
    array[end] = temp;
    print_array(array, size);
    end--;
    sift_down(array, 0, end, size);
  }
}
