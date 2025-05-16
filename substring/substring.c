#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * str_match_count - Count the matching occurrences of words in a substring
 * @substring: The substring to check
 * @words: Array of words to match
 * @nb_words: Number of words
 * @word_len: Length of each word
 * @word_count: Frequency of each word in the original words array
 *
 * Return: 1 if substring is valid, else 0
 */
int str_match_count(const char *substring, const char **words, int nb_words,
int word_len, int *word_count)
{
int *seen = calloc(nb_words, sizeof(int));
int i, j;

if (!seen)
return (0);

for (i = 0; i < nb_words; i++)
{
const char *word = substring + i * word_len;
for (j = 0; j < nb_words; j++)
{
if (!strncmp(word, words[j], word_len))
{
seen[j]++;
if (seen[j] > word_count[j])
{
free(seen);
return (0);
}
;
}
}
if (j == nb_words)
{
free(seen);
return (0);
}
}

free(seen);
return (1);
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
