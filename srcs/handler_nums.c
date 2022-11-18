/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:30:00 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 12:39:42 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_di(t_print *print, va_list valist)
{
	const int	max = maxi(print->width, print->preci);
	char		field[max + 1];
	char		x[12];
	int			pdiff;

	get_diu_str(print, x, va_arg(valist, int));
	set_compat(print);
	ft_memset(field, print->fillc, max);
	field[max] = '\0';
	pdiff = print->preci - ft_strlen(x);
	pdiff *= (pdiff >= 0);
	if (max == print->width && (comb_len(x, print->pref) + pdiff) <= max)
		return (set_field_diu(print, field, x, max));
	if (x[0] == '0' && print->preci == 0)
		return (fill_buf(print, print->pref, ft_strlen(print->pref)));
	if (fill_buf(print, print->pref, ft_strlen(print->pref)))
			return (-1);
	if (pdiff > 0 && fill_buf(print, field, pdiff) == -1)
		return (-1);
	return (fill_buf(print, x, -1));
}

int	hdl_u(t_print *print, va_list valist)
{
	const int	max = maxi(print->width, print->preci);
	char		field[max + 1];
	char		x[11];
	int			pdiff;

	get_diu_str(print, x, va_arg(valist, unsigned int));
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
}
