/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:46 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 02:23:12 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	valist;
	t_print print;

	va_start(valist, s);
	if (init_print(&print, s, &valist) == -1)
		return (-1);
	if (make_output(&print) == -1)
		return (va_end(valist), ft_lstclear(&(print.parts), free), -1);
	write_n_free(&(print.parts));
	va_end(valist);
	return (print.ret);
}
