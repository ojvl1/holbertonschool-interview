#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string.
 * @str: The input string.
 * @pattern: The regex pattern.
 *
 * Return: 1 if match, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
if (!pattern || !str)
{
return (0);
}

if (*pattern == '\0')
{
return (*str == '\0');
}


if (*(pattern + 1) == '*')
{
if ((*str != '\0' && (*str == *pattern || *pattern == '.')) &&
regex_match(str + 1, pattern)) {
return (1);
}
return (regex_match(str, pattern + 2));
}
if (*str != '\0' && (*str == *pattern || *pattern == '.'))
{
return (regex_match(str + 1, pattern + 1));
}
return (0);
}
