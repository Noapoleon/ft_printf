/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:10 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 02:07:08 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_c(t_print *print, va_list valist)
{
	char	c;
	char	field[print->width_s + 1];

	c = va_arg(valist, int);
	if (print->width_s > 1)
	{
		init_field(print, field, print->width_s);
		if (print->flags_s & FLAG_MINUS)
		   	field[0] = c;
		else
			field[print->width_s - 1] = c;
		return (fill_buf(print, field, print->width_s));
	}
	else
		return (fill_buf(print, &c, 1));
}

int	hdl_s(t_print *print, va_list valist)
{
	char		*s;
	int			len;
	const int	p = print->preci_s;
	const int	w = print->width_s;
	char		field[w + 1];

	init_field(print, field, w);
	s = va_arg(valist, char *);
	if (s == NULL)
		s = NULL_STR;
	len = ft_strlen(s);
	if (p == 0 || (s == (char *)NULL_STR && p < len && p != -1))
		return (fill_buf(print, field, w));
	else if (w == 0)
		return (fill_buf(print, s, mini(p, len)));
	else if ((mini(p, len) >= w) || (p == -1 && len >= w))
		return (fill_buf(print, s, -1));
	else
	{
		set_field_str(print, field, s, len);
		return (fill_buf(print, field, -1));
	}
}

int	hdl_ps(t_print *print, va_list valist)
{
	(void)valist;

	return (fill_buf(print, "%", 1));
}

//int	make_preci_str(t_print *print, char *
