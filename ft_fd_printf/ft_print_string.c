/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:07:31 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/17 21:16:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

int	ft_print_string(int fd, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write (fd, "(null)", 6));
	return (write (fd, str, ft_strlen(str)));
}
