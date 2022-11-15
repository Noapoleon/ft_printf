/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:10 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:53:18 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_c(t_print *print, va_list valist)
{
	char	c;

	c = va_arg(valist, int);
	if (fill_buf(print, &c, 1) == -1)
		return (-1);
	return (0);
}

int	hdl_s(t_print *print, va_list valist)
{
	char	*tmp;

	tmp = va_arg(valist, char *);
	if ((tmp == NULL) && (fill_buf(print, "(null)", 0) == -1))
		return (-1);
	else if (fill_buf(print, tmp, 0) == -1)
		return (-1);
//	free(tmp); // not sure that I need to free this here, va_end might do it on it's own
// if freeing is actually needed put it BEFORE the return -1 you idiot
// after thinking a bit i'm probably not meant to free pointers from va_arg as they're from the array of parameters (...)
	return (0);
}

int	hdl_ps(t_print *print, va_list valist)
{
	(void)valist;
	if (fill_buf(print, "%", 0) == -1)
		return (-1);
	return (0);
}
