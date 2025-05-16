#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * build_word_count_map - Count the matching occurrences
 * of words in a substring
 * @words: Array of words to match
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if substring is valid, else 0
 */
int *build_word_count_map(const char **words, int nb_words, int word_len)
{
int *word_count = calloc(nb_words, sizeof(int));
int i, j;

if (!word_count)
return (NULL);

for (i = 0; i < nb_words; i++)
{
for (j = 0; j < i; j++)
{
if (strncmp(words[i], words[j], word_len) == 0)
{
word_count[j]++;
break;
}
}
if (j == i)
word_count[i]++;
}
return (word_count);
}

/**
 * find_substring - Finds all starting indices of substring(s)
 * @s: The string to search
 * @words: Array of words
 * @nb_words: Number of words
 * @n: Pointer to result count
 *
 * Return: Array of indices
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len, i, count = 0;
	int *indices, *word_count;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);
	if (s_len < total_len)
		return (NULL);

	indices = malloc(sizeof(int) * (s_len - total_len + 1));
	if (!indices)
		return (NULL);

	word_count = build_word_count_map(words, nb_words, word_len);
	if (!word_count)
	{
		free(indices);
		return (NULL);
	}

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (str_match_count(s + i, words, nb_words, word_len, word_count))
			indices[count++] = i;
	}

	free(word_count);
	*n = count;
	return (count ? indices : NULL);
}
