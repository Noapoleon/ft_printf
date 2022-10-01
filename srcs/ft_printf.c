/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:29:27 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/01 16:27:12 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// WHEN IMPLEMENTING FLAGS
// change function 'putconv' for 'handleconv' so that there's no need
// to change 'ft_printf' function
// 'handleconv' will modify 's' itself to put it after the conversion in the
// original string
int ft_printf(const char *s, ...)
{
	int 	conv_count;
	size_t	lensub;
	va_list	valist;

	conv_count = count_conversions(s);
	if (conv_count == -1)
		return (1);
	else if (conv_count == 0)
		return (ft_putstr_fd((char *)s, 1), 0);
	va_start(valist, s);
	// put in function 'handle_conversions'
	while (*s)
	{
		lensub = len_to_conv(s);
		if (lensub == 0)
		{
			putconv(*(s + 1), &valist);
			s += 2;
		}
		else
		{
			write(1, s, lensub);
			s += lensub;
		}
	}
	// --- //
	return (0);
}
