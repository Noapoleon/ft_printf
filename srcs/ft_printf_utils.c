/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:01:14 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/01 17:27:06 by nlegrand         ###   ########.fr       */
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

void	putconv(const char c, va_list *valist)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*valist, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*valist, char *), 1);
	else if (c == 'p')
		putptr(va_arg(*valist, void *));
	else if ((c == 'd') || (c == 'i'))
		ft_putnbr_fd(va_arg(*valist, int), 1);
	else if (c == 'u')
		putuint(va_arg(*valist, unsigned int)); // NOT THOROUGHLY TESTED
	else if (c == 'x')
		puthex(va_arg(*valist, unsigned int), 0);
	else if (c == 'X')
		puthex(va_arg(*valist, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

size_t	len_to_conv(const char *s) // rework for edge cases
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr && (*ptr != '%'))
		++ptr;
	return (ptr - s);
}
