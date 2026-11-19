/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:07:23 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/18 23:42:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_print_integer(int fd, va_list args)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (-1);
	len = write (fd, str, ft_strlen(str));
	free(str);
	return (len);
}
