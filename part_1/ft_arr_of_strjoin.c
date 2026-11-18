#include "libft_push_swap.h"

static size_t	ft_arr_of_strlen(char **arr_of_str)
{
	size_t	len;

	len = 0;
	while (arr_of_str[len])
		len++;
	return (len);
}

char	**ft_arr_of_strjoin(char const **s1, char const **s2)
{
	char	**joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	if (s1)
		s1_len = ft_arr_of_strlen(s1);
	if (s2)
		s2_len = ft_arr_of_strlen(s2);
	joined = malloc (sizeof(char *) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	joined[s1_len + s2_len] = NULL;
	ft_memcpy(joined, s1, sizeof(char *) * s1_len);
	ft_memcpy(joined + s1_len, s2, sizeof(char *) * s2_len);
	return (joined);
}
