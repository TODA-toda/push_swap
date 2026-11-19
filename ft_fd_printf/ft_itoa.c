/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:26:35 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/18 23:42:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	intlen(long long *n, int *is_neg)
{
	int			len;
	long long	nb;

	nb = *n;
	*is_neg = 0;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		*n = -*n;
		len++;
		*is_neg = 1;
	}
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			len;
	int			is_neg;
	char		*itoa;

	nb = n;
	len = intlen(&nb, &is_neg);
	itoa = malloc (sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (nb == 0)
		itoa[0] = '0';
	while (nb)
	{
		itoa[len - 1] = nb % 10 + '0';
		len--;
		nb /= 10;
	}
	if (is_neg)
		itoa[0] = '-';
	return (itoa);
}
