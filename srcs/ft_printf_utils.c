/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 03:14:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_state(t_print *print, int mode, const char *s, int fd)
{
	if (mode == PRINT_INIT)
	{
		print->s = (char *)s;
		print->fd = fd;
		print->ret = 0;
		print->buf[0] = '\0';
		print->pos = 0;
	}
	print->convi = 0;
	print->convc = '\0';
	print->fillc = ' ';
	print->flags = 0;
	print->width = 0;
	print->preci = -1;
	print->pref = STR_ZERO;
	print->handler = NULL;
	print->bad = 0;
}

int	output_full(t_print *print)
{
	if (print->pos == PRINT_SIZE)
	{
		if (write(print->fd, print->buf, print->pos) == -1)
			return (-1);
		print->pos = 0;
	}
	return (0);
}

int	fill_buf(t_print *print, char *s, int n)
{
	int	len;

	len = 0;
	while ((n < 0 && s[len]) || (n > 0 && len < n))
	{
		if (n == -2 && s[len] == '%')
			break ;
		print->buf[print->pos++] = s[len++];
		if (output_full(print) == -1)
			return (-1);
	}
	// CHECK IF n == 0 HAS A USE
	print->ret += len;
	if (s == print->s)
		print->s += len;
	return (0);
}

int	atoi_safe(const char *nptr)
{
	long	nb;
	int		sign;

	nb = 0;
	while (*nptr && (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == ' ')))
		++nptr;
	sign = 1;
	if ((*nptr == '-') || (*nptr == '+'))
		if (*nptr++ == '-')
			sign = -1;
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		nb = (nb * 10) + (*nptr++ - 48);
		if (nb > INT_MAX && sign == 1)
			return (-1);
		if (nb > (long)INT_MAX + 1 && sign == -1)
			return (0);
	}
	return (sign * (int)nb);
}

int	maxi(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int mini(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	comb_len(char *a, char *b)
{
	return (ft_strlen(a) + ft_strlen(b));
}
