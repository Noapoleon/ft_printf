/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:59:56 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 12:48:27 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_x(t_print *print, va_list valist)
{
	const int	max = maxi(print->width, print->preci);
	char		field[max + 1];
	char		x[sizeof(unsigned int) * 2 + 1];
	int			pdiff;

	get_hex_str(print, x, va_arg(valist, unsigned int));
	set_compat(print);
	ft_memset(field, print->fillc, max);
	field[max] = '\0';
	pdiff = print->preci - ft_strlen(x);
	pdiff *= (pdiff >= 0);
	if (max == print->width && ((int)ft_strlen(x) + pdiff) <= max)
		return (set_field_diu(print, field, x, max));
	if (x[0] == '0' && print->preci == 0)
		return (0);
	if (pdiff > 0 && fill_buf(print, field, pdiff) == -1)
		return (-1);
	return (fill_buf(print, x, -1));
} // erase and use hdl_di

//int	hdl_x(t_print *print, va_list valist)
//{
//	char		x[sizeof(unsigned int) * 2];
//	const int	max = maxi(print->width, print->preci);
//	char		field[max + 1]; // check if it works when strlen(x) > max
//	const int	f = print->flags;
//	char		*pre;
//
//	pre = PREF_XL;
//	if (print->convc == 'X')
//		pre = PREF_XU;
//	get_hex_str(x, va_arg(valist, unsigned int), print->convc == 'X');
//	if (f & FM_ZERO && !(f & FM_MINUS || print->preci != -1))
//		ft_memset(field, '0', max);
//	else
//		ft_memset(field, ' ', max);
//	field[max] = '\0';
//	if (x[0] == '0'	&& !print->preci)
//		return (fill_buf(print, field, -1));
//	if ((int)ft_strlen(x) >= max || 
//			(f & FM_HASH && (int)ft_strlen(x) + 2 >= max))
//	{
//		if (fill_buf(print, pre, (f & FM_HASH && x[0] != '0') * 2) == -1)
//			return (-1);
//		return (fill_buf(print, x, -1));
//	}
//	return (set_field_hex(print, field, x, max));
//}

int	hdl_p(t_print *print, va_list valist)
{
	const size_t	n = va_arg(valist, size_t);
	char			x[sizeof(size_t) * 2 + 2];
	const int		max = maxi(print->width, print->preci);
	char			field[max + 1]; // check if it works when strlen(x) > max
	const int		f = print->flags;

	ft_memcpy(x, "0x", 2);
	get_hex_str(x + 2, n, print->convc == 'X');
	if (n == 0)
		ft_strlcpy(x, STR_NIL, 6);
	if (f & FM_ZERO && !(f & FM_MINUS || print->preci != -1))
		ft_memset(field, '0', max);
	else
		ft_memset(field, ' ', max);
	field[max] = '\0';
	if (!n && !print->preci)
		return (fill_buf(print, field, -1));
	if ((int)ft_strlen(x) >= max)
		return (fill_buf(print, x, -1));
	return (set_field_hex(print, field, x, max));
}
