/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souait-s <souait-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:07:20 by souait-s          #+#    #+#             */
/*   Updated: 2026/10/30 18:07:20 by souait-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	intlen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	*ft_itohex(uintptr_t n)
{
	int		len;
	char	*itohex;
	char	*hex;

	len = intlen(n) + 2;
	itohex = malloc (sizeof(char) * (len + 1));
	if (!itohex)
		return (NULL);
	itohex[len] = '\0';
	itohex[0] = '0';
	itohex[1] = 'x';
	hex = "0123456789abcdef";
	while (n)
	{
		itohex[len - 1] = hex[n % 16];
		len--;
		n /= 16;
	}
	return (itohex);
}

int	ft_print_hex(int fd, va_list args)
{
	char	*str;
	int		len;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write (fd, "(nil)", 5));
	str = ft_itohex((uintptr_t)ptr);
	if (!str)
		return (-1);
	len = write (fd, str, ft_strlen(str));
	free(str);
	return (len);
}
