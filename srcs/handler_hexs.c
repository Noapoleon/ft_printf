/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:59:56 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 19:50:45 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_x(t_print *print, va_list valist)
{
	char		x[sizeof(unsigned int) * 2];
	const int	max = maxi(print->width_s, print->preci_s);
	char		field[max + 1]; // check if it works when strlen(x) > max
	const int	f = print->flags_s;
	char		*pre;

	pre = ALT_L;
	if (conv_char(print) == 'X')
		pre = ALT_U;
	get_hexstr(x, va_arg(valist, unsigned int), conv_char(print) == 'X');
	if (f & F_ZERO && !(f & F_MINUS || print->preci_s != -1))
		ft_memset(field, '0', max);
	else
		ft_memset(field, ' ', max);
	field[max] = '\0';
	if (x[0] == '0'	&& !print->preci_s)
		return (fill_buf(print, field, -1));
	if ((int)ft_strlen(x) >= max || 
			(f & F_HASH && (int)ft_strlen(x) + 2 >= max))
	{
		if (fill_buf(print, pre, (f & F_HASH && x[0] != '0') * 2) == -1)
			return (-1);
		return (fill_buf(print, x, -1));
	}
	return (set_field_hex(print, field, x, max));
}

int	hdl_p(t_print *print, va_list valist)
{
	const size_t	n = va_arg(valist, size_t);
	char			x[sizeof(size_t) * 2 + 2];
	const int		max = maxi(print->width_s, print->preci_s);
	char			field[max + 1]; // check if it works when strlen(x) > max
	const int		f = print->flags_s;

	ft_memcpy(x, "0x", 2);
	get_hexstr(x + 2, n, conv_char(print) == 'X');
	if (n == 0)
		ft_strlcpy(x, NIL_STR, 6);
	if (f & F_ZERO && !(f & F_MINUS || print->preci_s != -1))
		ft_memset(field, '0', max);
	else
		ft_memset(field, ' ', max);
	field[max] = '\0';
	if (!n && !print->preci_s)
		return (fill_buf(print, field, -1));
	if ((int)ft_strlen(x) >= max)
		return (fill_buf(print, x, -1));
	return (set_field_hex(print, field, x, max));
}
