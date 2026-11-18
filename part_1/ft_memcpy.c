#include "libft_push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*des;
	const char	*sr;
	size_t		i;

	des = dest;
	sr = src;
	i = 0;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (dest);
}
