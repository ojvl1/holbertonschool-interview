#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - finds all starting indices of substrings in s
 * @s: the input string
 * @words: the list of words to match
 * @nb_words: the number of words
 * @n: pointer to the output size
 * Return: array of starting indices of valid substrings
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
int *indices = NULL;
int i, j, k, index = 0;
int s_len, word_len, window_len;
char **check;
int match;

if (!s || !words || nb_words == 0)
{
	*n = 0;
return (NULL);
}

s_len = strlen(s);
word_len = strlen(words[0]);
window_len = word_len *nb_words;

if (s_len < window_len)
{
*n = 0;
return (NULL);
}

indices = malloc(sizeof(int) * (s_len - window_len + 1));
if (!indices)
return (NULL);

for (i = 0; i <= s_len - window_len; i++)
{
check = malloc(sizeof(char *) * nb_words);
if (!check)
return (NULL);

for (j = 0; j < nb_words; j++)
check[j] = NULL;

match = 1;
for (j = 0; j < nb_words; j++)
{
const char *sub = s + i + j * word_len;
match = 0;
for (k = 0; k < nb_words; k++)
{
if (!check[k] && strncmp(sub, words[k], word_len) == 0)
{
check[k] = (char *)sub;
match = 1;
break;
}
}
if (!match)
break;
}

if (match)
indices[index++] = i;

free(check);
}

*n = index;
if (index == 0)
{
free(indices);
return (NULL);
}
return (indices);
}
