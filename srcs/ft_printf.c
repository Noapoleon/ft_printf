/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:46 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 00:11:26 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	valist;
	int ret;

	va_start(valist, s);
	ret = w_vdprintf(PRINT_FD, s, valist);
	va_end(valist);
	return (ret);
}

int	w_vdprintf(int fd, const char *s, va_list valist)
{
	t_print print;

	print_state(&print, PRINT_INIT, s, fd);
	while (*(print.s))
	{
		if (*(print.s) == '%')
		{
			if (set_conv_state(&print) == -1)
				return (write(fd, print.buf, print.pos), -1);
			else if (print.handler_s(&print, valist) == -1)
				return (-1);
		}
		else if (fill_buf(&print, print.s, -2) == -1)
			return (-1);
	}
	if (write(fd, print.buf, print.pos) == -1)
		return (-1);
	return (print.ret);
}

