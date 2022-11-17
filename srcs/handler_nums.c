/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:30:00 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 22:07:37 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_di(t_print *print, va_list valist)
{
	char		x[12];
	const int	max = maxi(print->width_s, print->preci_s);
	char		field[max + 1]; // check if it works when strlen(x) > max
	const int	f = print->flags_s;
	char		*prefix;

	prefix = get_prefix(print, x[0]);
	get_diustr(x, va_arg(valist, int));
	if (f & F_ZERO && !(f & F_MINUS || print->preci_s != -1))
		ft_memset(field, '0', max);
	else
		ft_memset(field, ' ', max);
	field[max] = '\0';
	if (x[0] == '0'	&& !print->preci_s)
		return (fill_buf(print, field, -1));
	if ((int)ft_strlen(x) >= max)
		return (fill_buf(print, x, -1));
	return (set_field_hex(print, field, x, max));
}
//int	hdl_di(t_print *print, va_list valist)
//{
//	int		n;
//	char	*tmp;
//
//	n = va_arg(valist, int);
//	tmp = ft_itoa(n);
//	if (tmp == NULL)
//		return (-1);
//	if (fill_buf(print, tmp, -1) == -1)
//		return (free(tmp), -1);
//	return (free(tmp), 0);
//}

int	hdl_u(t_print *print, va_list valist)
{
	char		x[11];
	const int	max = maxi(print->width_s, print->preci_s);
	char		field[max + 1]; // check if it works when strlen(x) > max
	const int	f = print->flags_s;

	get_diustr(x, va_arg(valist, unsigned int));
	if (f & F_ZERO && !(f & F_MINUS || print->preci_s != -1))
		ft_memset(field, '0', max);
	else
		ft_memset(field, ' ', max);
	field[max] = '\0';
	if (x[0] == '0'	&& !print->preci_s)
		return (fill_buf(print, field, -1));
	if ((int)ft_strlen(x) >= max)
		return (fill_buf(print, x, -1));
	return (set_field_hex(print, field, x, max));
}
