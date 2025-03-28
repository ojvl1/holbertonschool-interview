#include "holberton.h"

/**
 * wildcmp - Compares two strings considering '*' as a wildcard.
 * @s1: First string.
 * @s2: Second string (can contain '*').
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '\0')
return (*s1 == '\0');

if (*s2 == '*')
{
if (*(s2 + 1) == '\0')
return (1);
if (*s1 != '\0' && wildcmp(s1 + 1, s2))
return (1);
return (wildcmp(s1, s2 + 1));
}

if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));

return (0);
}
