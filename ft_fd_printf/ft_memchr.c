/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:26:40 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/17 21:15:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*mem;
	size_t		i;

	mem = s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (char)c)
			return ((char *)&mem[i]);
		i++;
	}
	return (NULL);
}
