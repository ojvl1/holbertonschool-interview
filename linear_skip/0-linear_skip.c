#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
  skiplist_t *express, *prev;

  if (list == NULL)
    return (NULL);

  express = list->express;
  prev = list;

  /* Traverse the express lane */
  while (express != NULL && express->n < value)
  {
    printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    prev = express;
    express = express->express;
  }

  /* If express is NULL, we need to traverse the normal lane from the last express node */
  if (express == NULL)
  {
    express = prev;
    while (express->next != NULL)
      express = express->next;
  }

  printf("Value found between indexes [%lu] and [%lu]\n", prev->index, express->index);

  /* Traverse the normal lane between prev and express */
  while (prev != NULL && prev->index <= express->index)
  {
    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    if (prev->n == value)
      return (prev);
    prev = prev->next;
  }

  return (NULL);
}