/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souait-s <souait-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:29:53 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/19 23:47:23 by souait-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	copy[len] = '\0';
	ft_memcpy(copy, s, len);
	return (copy);
}
