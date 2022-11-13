/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:01:14 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/02 15:32:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	putconv(const char c, va_list *valist, int *ret)
{
	if (c == 'c')
		handle_char(valist, ret);
	else if (c == 's')
		handle_str(valist, ret);
	else if (c == 'p')
		handle_ptr(valist, ret);
	else if ((c == 'd') || (c == 'i'))
		handle_di(valist, ret);
	else if (c == 'u')
		handle_uint(valist, ret);
	else if (c == 'x')
		handle_hex(0, valist, ret);
	else if (c == 'X')
		handle_hex(1, valist, ret);
	else if (c == '%')
		handle_percent(ret);
}

size_t	len_to_conv(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr && (*ptr != '%'))
		++ptr;
	return (ptr - s);
}

void	handle_conversions(const char *s, int *ret, va_list *valist)
{
	size_t	lensub;

	while (*s)
	{
		lensub = len_to_conv(s);
		if (lensub == 0)
		{
			putconv(*(s + 1), valist, ret);
			s += 2;
		}
		else
		{
			write(1, s, lensub);
			*ret += lensub;
			s += lensub;
		}
	}
}
