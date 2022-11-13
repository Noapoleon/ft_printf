/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:29:27 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/02 15:14:56 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// WHEN IMPLEMENTING FLAGS
// change function 'putconv' for 'handleconv' so that there's no need
// to change 'ft_printf' function
// 'handleconv' will modify 's' itself to put it after the conversion in the
// original string
int	ft_printf(const char *s, ...)
{
	int		conv_count;
	va_list	valist;
	int		ret;

	conv_count = count_conversions(s);
	if (conv_count == -1)
		return (1);
	else if (conv_count == 0)
		return (ft_putstr_fd((char *)s, 1), ft_strlen(s));
	va_start(valist, s);
	ret = 0;
	handle_conversions(s, &ret, &valist);
	return (ret);
}
