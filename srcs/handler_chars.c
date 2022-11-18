/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:10 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 03:10:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_c(t_print *print, va_list valist)
{
	char	c;
	char	field[print->width + 1];

	c = va_arg(valist, int);
	if (print->width > 1)
	{
		ft_memset(field, ' ', print->width);
//		init_field(print, field, print->width);
		if (print->flags & FM_MINUS)
		   	field[0] = c;
		else
			field[print->width - 1] = c;
		return (fill_buf(print, field, print->width));
	}
	else
		return (fill_buf(print, &c, 1));
}

int	hdl_s(t_print *print, va_list valist)
{
	char		*s;
	int			len;
	const int	p = print->preci;
	const int	w = print->width;
	char		field[w + 1];

//	init_field(print, field, w);
	ft_memset(field, ' ', w);
	s = va_arg(valist, char *);
	if (s == NULL)
		s = STR_NULL;
	len = ft_strlen(s);
	if (p == 0 || (s == (char *)STR_NULL && p < len && p != -1))
		return (fill_buf(print, field, w));
	if (w == 0)
		return (fill_buf(print, s, mini(p, len)));
	if ((mini(p, len) >= w) || (p == -1 && len >= w))
		return (fill_buf(print, s, -1));
	set_field_str(print, field, s, len);
	return (fill_buf(print, field, -1));
}

int	hdl_ps(t_print *print, va_list valist)
{
	(void)valist;

	return (fill_buf(print, "%", 1));
}

//int	make_precitr(t_print *print, char *
