/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souait-s <souait-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:07:25 by souait-s          #+#    #+#             */
/*   Updated: 2026/10/30 18:07:25 by souait-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

static int	intlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	*ft_itolowhex(unsigned int n)
{
	int		len;
	char	*itohex;
	char	*hex;

	len = intlen(n);
	itohex = malloc (sizeof(char) * (len + 1));
	if (!itohex)
		return (NULL);
	itohex[len] = '\0';
	if (n == 0)
		itohex[0] = '0';
	hex = "0123456789abcdef";
	while (n)
	{
		itohex[len - 1] = hex[n % 16];
		len--;
		n /= 16;
	}
	return (itohex);
}

int	ft_print_lowhex(int fd, va_list args)
{
	char	*str;
	int		len;

	str = ft_itolowhex(va_arg(args, unsigned int));
	if (!str)
		return (-1);
	len = write (fd, str, ft_strlen(str));
	free(str);
	return (len);
}
