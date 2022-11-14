/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:46 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:35:57 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	valist;
	int ret;

	va_start(valist, s);
	ret = w_vdprintf(OUT_FD, s, valist);
	va_end(valist);
	return (ret);
}

int	w_vdprintf(int fd, const char *s, va_list valist)
{
	t_print print;

	if (init_print(&print, s) == -1)
		return (-1);
	if (make_output(&print, valist) == -1)
		return (ft_lstclear(&(print.parts), free), -1);
	write_n_free(&(print.parts), fd);
	return (print.ret);
}

