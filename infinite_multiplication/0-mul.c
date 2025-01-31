#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_valid_number - Checks if a string is composed of digits.
 * @num: The string to validate.
 * Return: 1 if valid, 0 otherwise.
 */
int is_valid_number(const char *num)
{
  for (int i = 0; num[i]; i++)
  {
    if (num[i] < '0' || num[i] > '9')
      return (0);
  }
  return (1);
}

/**
 * remove_leading_zeros - Removes leading zeros from a number string.
 * @num: The input number string.
 * Return: A new string without leading zeros.
 */
char *remove_leading_zeros(const char *num)
{
  int len = strlen(num);
  int start = 0;

  while (start < len && num[start] == '0')
    start++;

  if (start == len)
  {
    char *res = malloc(2);
    res[0] = '0';
    res[1] = '\0';
    return (res);
  }

  char *res = malloc(len - start + 1);
  strcpy(res, num + start);
  return (res);
}

/**
 * reverse_str - Reverses a string.
 * @s: The string to reverse.
 * Return: A new reversed string.
 */
char *reverse_str(const char *s)
{
  int len = strlen(s);
  char *reversed = malloc(len + 1);

  for (int i = 0; i < len; i++)
    reversed[i] = s[len - 1 - i];
  reversed[len] = '\0';

  return (reversed);
}

/**
 * multiply_numbers - Multiplies two reversed number strings.
 * @reversed_num1: First reversed number.
 * @reversed_num2: Second reversed number.
 * @len1: Length of first number.
 * @len2: Length of second number.
 * Return: Array of integers representing the product.
 */
int *multiply_numbers(char *reversed_num1, char *reversed_num2, int len1, int len2)
{
  int max_len = len1 + len2;
  int *result = calloc(max_len + 1, sizeof(int));

  for (int i = 0; i < len2; i++)
  {
    int digit2 = reversed_num2[i] - '0';
    for (int j = 0; j < len1; j++)
    {
      int digit1 = reversed_num1[j] - '0';
      result[i + j] += digit1 * digit2;
    }
  }

  for (int i = 0; i < max_len; i++)
  {
    int carry = result[i] / 10;
    result[i] %= 10;
    result[i + 1] += carry;
  }

  return (result);
}

/**
 * build_result_string - Constructs the product string from the result array.
 * @result: The array containing product digits.
 * @max_len: Maximum length of the result array.
 * Return: The product as a string.
 */
char *build_result_string(int *result, int max_len)
{
  int highest = max_len;
  while (highest >= 0 && result[highest] == 0)
    highest--;

  if (highest < 0)
    return (strdup("0"));

  char *product = malloc(highest + 2);
  int pos = 0;

  for (int i = highest; i >= 0; i--)
    product[pos++] = result[i] + '0';
  product[pos] = '\0';

  return (product);
}

/**
 * main - Entry point for multiplying two large numbers.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Error\n");
    exit(98);
  }

  if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
  {
    printf("Error\n");
    exit(98);
  }

  char *num1_clean = remove_leading_zeros(argv[1]);
  char *num2_clean = remove_leading_zeros(argv[2]);

  if (strcmp(num1_clean, "0") == 0 || strcmp(num2_clean, "0") == 0)
  {
    printf("0\n");
    free(num1_clean);
    free(num2_clean);
    exit(0);
  }

  char *reversed_num1 = reverse_str(num1_clean);
  char *reversed_num2 = reverse_str(num2_clean);
  free(num1_clean);
  free(num2_clean);

  int len1 = strlen(reversed_num1);
  int len2 = strlen(reversed_num2);
  int *result = multiply_numbers(reversed_num1, reversed_num2, len1, len2);
  char *product = build_result_string(result, len1 + len2);

  printf("%s\n", product);

  free(result);
  free(reversed_num1);
  free(reversed_num2);
  free(product);

  return (0);
}
