/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:36:06 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/18 23:43:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
