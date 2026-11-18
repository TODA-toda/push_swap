/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souait-s <souait-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:07:34 by souait-s          #+#    #+#             */
/*   Updated: 2026/10/30 18:07:34 by souait-s         ###   ########.fr       */
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
		n /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*itoa;

	len = intlen(n);
	itoa = malloc (sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (n == 0)
		itoa[0] = '0';
	while (n)
	{
		itoa[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (itoa);
}

int	ft_print_uinteger(int fd, va_list args)
{
	char	*str;
	int		len;

	str = ft_uitoa(va_arg(args, unsigned int));
	if (!str)
		return (-1);
	len = write (fd, str, ft_strlen(str));
	free(str);
	return (len);
}
