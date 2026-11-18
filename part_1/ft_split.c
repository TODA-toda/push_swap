#include "libft_push_swap.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	if (!s)
		return (0);
	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static size_t	count_word_len(char const *s, char c, size_t *i)
{
	size_t	counter;

	counter = 0;
	while (s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		counter++;
		(*i)++;
	}
	return (counter);
}

static void	*free_it(char **splited, size_t i)
{
	while (i > 0)
	{
		i--;
		free(splited[i]);
	}
	free(splited);
	return (NULL);
}

static void	fill(char *dest, char const *src, size_t word_len, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < word_len)
	{
		dest[word_len - 1 - i] = src[pos - 1 - i];
		i++;
	}
	dest[word_len] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	size_t	splited_len;
	size_t	i;
	size_t	word_len;
	size_t	pos;

	splited_len = count_word(s, c);
	if (!splited_len)
		return (NULL);
	splited = malloc (sizeof(char *) * (splited_len + 1));
	if (!splited)
		return (NULL);
	splited[splited_len] = NULL;
	pos = 0;
	i = 0;
	while (i < splited_len)
	{
		word_len = count_word_len(s, c, &pos);
		splited[i] = malloc (sizeof(char) * (word_len + 1));
		if (!splited[i])
			return (free_it(splited, i));
		fill(splited[i++], s, word_len, pos);
	}
	return (splited);
}
