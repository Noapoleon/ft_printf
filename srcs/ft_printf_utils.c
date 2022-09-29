/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:01:14 by nlegrand          #+#    #+#             */
/*   Updated: 2022/09/29 18:15:00 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_setchar(const char *set, const char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

int	count_conversions(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '%' && is_setchar(CONV_SET, *(s + 1)))
		{
			s += 1;
			++count;
		}
		else if (*s == '%')
			return (-1);
		++s;
	}
	return (count);
}

void	putconv(const char c)
{
	if (c == 'c')
		write(1, "CHAR", 4);
	else if (c == 's')
		ft_putstr_fd("STR", 1);
	else if (c == 'p')
		ft_putstr_fd("PTR", 1);
	else if (c == 'd')
		ft_putstr_fd("DEC", 1);
	else if (c == 'i')
		ft_putstr_fd("INT", 1);
	else if (c == 'u')
		ft_putstr_fd("UNS", 1);
	else if (c == 'x')
		ft_putstr_fd("HEX", 1);
	else if (c == 'X')
		ft_putstr_fd("BIGHEX", 1);
	else if (c == '%')
		ft_putstr_fd("DUP", 1);
}

size_t	len_to_conv(const char *s) // rework for edge cases
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr && (*ptr != '%'))
		++ptr;
	return (ptr - s);
}
