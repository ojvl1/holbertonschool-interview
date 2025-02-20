#include "sort.h"

/**
 * merge - Merges two sorted subarrays.
 * @array: The original array.
 * @temp: Temporary array used for merging.
 * @left: Left index.
 * @mid: Middle index.
 * @right: Right index.
 */

void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = left;

printf("Merging...\n[left]: ");
print_array(array + left, mid - left);
printf("[right]: ");
print_array(array + mid, right - mid);

while (i < mid && j < right)
{
if (array[i] <= array[j])
{
temp[k++] = array[i++];
}
else
{
temp[k++] = array[j++];
}
}


while (i < mid)
{
temp[k++] = array[i++];
}

while (j < right)
{
temp[k++] = array[j++];
}

for (i = left; i < right; i++)
{
array[i] = temp[i];
}

printf("[Done]: ");
print_array(array + left, right - left);
}

/**
 * merge_sort_helper - Recursively splits and merges the array.
 * @array: The array to be sorted.
 * @temp: Temporary array for merging.
 * @left: Left index.
 * @right: Right index.
 */
void merge_sort_helper(int *array, int *temp, size_t left, size_t right)
{
if (right - left < 2)
{
return;
}

size_t mid = left + (right - left) / 2;

merge_sort_helper(array, temp, left, mid);
merge_sort_helper(array, temp, mid, right);
merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
if (size < 2)
{
return;
}

int *temp = malloc(sizeof(int) * size);
if (!temp)
{
return;
}

merge_sort_helper(array, temp, 0, size);
free(temp);
}
