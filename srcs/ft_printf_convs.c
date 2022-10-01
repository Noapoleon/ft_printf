/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:32 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/02 00:56:29 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list *valist, int *ret)
{
	*ret += 1;
	ft_putchar_fd((char)va_arg(*valist, int), 1);
}

void	handle_str(va_list *valist, int *ret)
{
	char *tmp;

	tmp = va_arg(*valist, char *);
	*ret += ft_strlen(tmp);
	ft_putstr_fd(tmp, 1);
}

void	handle_ptr(va_list *valist, int *ret)
{
	unsigned long	ptr_n;
	char			ptr_s[15];
	unsigned int	i;

	ptr_n = va_arg(*valist, unsigned long long);
	*ret += 14;
	ptr_s[0] = '0';
	ptr_s[1] = 'x';
	ptr_s[14] = '\0';
	i = 13;
	while (i >= 2)
	{
		if ((ptr_n % 16) < 10)
			ptr_s[i] = '0' + (ptr_n % 16);
		else
			ptr_s[i] = 'a' + (ptr_n % 16 - 10);
		ptr_n /= 16;
		--i;
	}
	write(1, ptr_s, 15);
}

void	handle_di(va_list *valist, int *ret)
{
	int	n;
	int	len;

	n = va_arg(*valist, int);
	ft_putnbr_fd(n, 1);
	len = 1;
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	*ret += len;
}

void	handle_uint(va_list *valist, int *ret)
{
	unsigned long	nn;
	unsigned long	pow;
	int				len;
	char			tmp;

	nn = va_arg(*valist, unsigned int);
	pow = 1;
	len = 1;
	while ((nn / pow) >= 10)
	{
		pow *= 10;
		++len;
	}
	*ret += len;
	while (pow > 0)
	{
		tmp = '0' + ((nn / pow) % 10);
		write(1, &tmp, 1);
		pow /= 10;
	}
}

void	handle_hex(int caps, va_list *valist, int *ret)
{
	unsigned long	n;
	unsigned long	pow;
	char			tmp;
	int				len;

	n = va_arg(*valist, unsigned int);
	pow = 1;
	len = 1;
	while ((n / pow) >= 16)
	{
		pow *= 16;
		++len;
	}
	*ret += len;
	while (pow > 0)
	{
		if (((n / pow) % 16) < 10)
			tmp = '0' + ((n / pow) % 16);
		else
			tmp = 'a' + ((n / pow) % 16 - 10) - (caps * 32);
		pow /= 16;
		write(1, &tmp, 1);
	}
}

void	handle_percent(int *ret)
{
	*ret += 1;
	write(1, "%", 1);
}
