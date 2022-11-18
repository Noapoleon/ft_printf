/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:30:00 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 18:35:37 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// appends a signed decimal conversion to buffer
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
	pdiff = print->preci - print->gxl;
	pdiff *= (pdiff >= 0);
	if (max == print->width && (comb_len(x, print->pref) + pdiff) <= max)
		return (set_field_nums(print, field, x, max));
	if (x[0] == '0' && print->preci == 0)
		return (fill_buf(print, print->pref, ft_strlen(print->pref)));
	if (fill_buf(print, print->pref, ft_strlen(print->pref)))
			return (-1);
	if (pdiff > 0 && fill_buf(print, field, pdiff) == -1)
		return (-1);
	return (fill_buf(print, x, -1));
}

// appends an unsigned decimal conversion to buffer
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
	pdiff = print->preci - print->gxl;
	pdiff *= (pdiff >= 0);
	if (max == print->width && (print->gxl + pdiff) <= max)
		return (set_field_nums(print, field, x, max));
	if (x[0] == '0' && print->preci == 0)
		return (0);
	if (pdiff > 0 && fill_buf(print, field, pdiff) == -1)
		return (-1);
	return (fill_buf(print, x, -1));
}

// appends an usigned hexadecimal conversion to buffer
int	hdl_x(t_print *print, va_list valist)
{
	const int	max = maxi(print->width, print->preci);
	char		field[max + 1];
	char		x[sizeof(unsigned int) * 2 + 1];
	int			pdiff;

	get_hex_str(print, x, va_arg(valist, unsigned int), print->convc == 'X');
	set_compat(print);
	ft_memset(field, print->fillc, max);
	field[max] = '\0';
	pdiff = print->preci - print->gxl;
	pdiff *= (pdiff >= 0);
	if (x[0] == '0')
		print->pref = STR_ZERO;
	if (max == print->width && (comb_len(x, print->pref) + pdiff) <= max)
		return (set_field_nums(print, field, x, max));
	if (x[0] == '0' && print->preci == 0)
		return (0);
	if (fill_buf(print, print->pref, ft_strlen(print->pref)))
			return (-1);
	if (pdiff > 0 && fill_buf(print, field, pdiff) == -1)
		return (-1);
	return (fill_buf(print, x, -1));
}

// appends a pointer address conversion to buffer
int	hdl_p(t_print *print, va_list valist)
{
	const int	max = maxi(print->width, print->preci);
	char		field[max + 1];
	char		x[sizeof(size_t) * 2 + 1];
	int			pdiff;

	get_hex_str(print, x, va_arg(valist, size_t), 0);
	set_compat(print);
	ft_memset(field, print->fillc, max);
	field[max] = '\0';
	pdiff = print->preci - print->gxl;
	pdiff *= (pdiff >= 0);
	if (x[0] == '0')
	{
		print->pref = STR_ZERO;
		ft_strlcpy(x, STR_NIL, ft_strlen(STR_NIL) + 1);
	}
	if (max == print->width && (comb_len(x, print->pref) + pdiff) <= max)
		return (set_field_nums(print, field, x, max));
	if (x[0] == '0' && print->preci == 0)
		return (0);
	if (fill_buf(print, print->pref, ft_strlen(print->pref)))
			return (-1);
	if (pdiff > 0 && fill_buf(print, field, pdiff) == -1)
		return (-1);
	return (fill_buf(print, x, -1));
}
