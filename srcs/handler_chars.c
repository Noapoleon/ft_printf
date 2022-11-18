/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:10 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 18:59:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// appends char conversion to buffer
int	hdl_c(t_print *print, va_list valist)
{
	char	c;
	char	field[print->width + 1];

	c = va_arg(valist, int);
	if (print->width > 1)
	{
		ft_memset(field, ' ', print->width);
		if (print->flags & FM_MINUS)
		   	field[0] = c;
		else
			field[print->width - 1] = c;
		return (fill_buf(print, field, print->width));
	}
	else
		return (fill_buf(print, &c, 1));
}

// apprends string conversion to buffer
int	hdl_s(t_print *print, va_list valist)
{
	char		*x;
	char		field[print->width + 1];
	int			max;

	x = va_arg(valist, char *);
	if (x == NULL && (int)ft_strlen(STR_NULL) > print->preci
			&& print->preci != -1)
		x = STR_ZERO;
	else if (x == NULL)
		x = STR_NULL;
	print->gxl = ft_strlen(x);
	max = mini(print->preci, print->gxl);
	max = (max != -1) * max + (max == -1) * print->gxl;
	set_compat(print);
	ft_memset(field, ' ', print->width);
	field[print->width] = '\0';
	if (print->width > max)
		return (set_field_str(print, field, x, max));
	if (max == print->gxl)
		return (fill_buf(print, x, -1));
	else
		return (fill_buf(print, x, max));
}

// appends % conversion to buffer
int	hdl_ps(t_print *print, va_list valist)
{
	(void)valist;

	return (fill_buf(print, "%", 1));
}

// appends buffer with the proper format for a failed conversion
int	hdl_bad(t_print *print, va_list valist)
{
	(void)valist;
	
	set_compat(print);
	fill_buf(print, "BAD_CONV", 8); // FUCKING CHANGE THIS
	return (0);
}
