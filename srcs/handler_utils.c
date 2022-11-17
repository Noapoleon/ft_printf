/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:18 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 20:54:37 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_hexstr(char *x, size_t n, int caps)
{
	size_t	pow;
	int		len;

	pow = 1;
	len = 1;
	while ((n / pow) >= 16)
	{
		pow *= 16;
		++len;
	}
	len = 0;
	while (pow > 0)
	{
		x[len++] = *(HEX_SET + ((n / pow) % 16));
		if (caps && ft_isalpha(x[len - 1]))
				x[len - 1] -= 32;
		pow /= 16;
	}
	x[len] = '\0';
}

void	get_diustr(char *x, long n)
{
	long	nn;
	long	pow;
	long	len;

	nn = n * (1 - (n < 0) * 2);
	pow = 1;
	len = 1;
	while ((nn / pow) >= 10)
	{
		pow *= 10;
		++len;
	}
	x[0] = '-';
	len = n < 0;
	while (pow > 0)
	{
		x[len++] = '0' + ((nn / pow) % 10);
		pow /= 10;
	}
	x[len] = '\0';
}

char	conv_char(t_print *print)
{
	int	mask;
	int i;

	mask = 1;
	i = 0;
	while (mask != print->conv_s)
	{
		mask *= 2;
		++i;
		}
	return (CONV_SET[i]);
}

int	hdl_bad(t_print *print, va_list valist)
{
	(void)valist;
	fill_buf(print, "BAD_CONV", 8); // FUCKING CHANGE THIS
	return (0);
}
