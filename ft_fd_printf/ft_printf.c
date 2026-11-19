/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:07:40 by souait-s          #+#    #+#             */
/*   Updated: 2026/11/18 23:42:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	fill(int (*conversions[9])(int, va_list))
{
	conversions[0] = ft_print_character;
	conversions[1] = ft_print_string;
	conversions[2] = ft_print_hex;
	conversions[3] = ft_print_integer;
	conversions[4] = ft_print_integer;
	conversions[5] = ft_print_uinteger;
	conversions[6] = ft_print_lowhex;
	conversions[7] = ft_print_upphex;
	conversions[8] = ft_print_percent;
}

static int	get_id(char *str, char c, size_t *pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	*pos += 2;
	return (i);
}

int	ft_printf(int fd, const char *format, ...)
{
	size_t	i;
	int		counter;
	va_list	args;
	int		res;
	int		(*conversions[9])(int, va_list);

	if (!format)
		return (-1);
	va_start(args, format);
	fill (conversions);
	counter = 0;
	res = 0;
	i = 0;
	while (format[i] && res != -1)
	{
		if (format[i] == '%' && ft_memchr("cspdiuxX%", format[i + 1], 9))
			res = conversions[get_id("cspdiuxX%", format[i + 1], &i)](fd, args);
		else
			res = write (fd, &format[i++], 1);
		counter += res;
	}
	va_end(args);
	if (res == -1)
		return (-1);
	return (counter);
}
