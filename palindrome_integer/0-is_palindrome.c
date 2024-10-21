#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

/**
 * is_palindrome - Checks if a given unsigned integer is a palindrome.
 * @n: The number to check.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
  unsigned long reversed = 0, original = n, remainder;

  while (n != 0)
  {
    remainder = n % 10;
    reversed = reversed * 10 + remainder;
    n /= 10;
  }

  if (original == reversed)
    return (1);
  else
    return (0);
}
