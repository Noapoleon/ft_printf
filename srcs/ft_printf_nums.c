/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:32 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/02 21:54:48 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*make_hex_str(unsigned long n)
{
	char			*str;
	char			*og_str;
	unsigned long	pow;

	pow = 1;
	while ((n / pow) >= 16)
		pow *= 16;
	str = (char *)malloc(sizeof(char) * 17);
	if (str == NULL)
		return (NULL);
	og_str = str;
	while (pow != 0)
	{
		if (((n / pow) % 16) < 10)
			*str++ = '0' + ((n / pow) % 16);
		else
			*str++ = 'a' + ((n / pow) % 16 - 10);
		pow /= 16;
	}
	*str = '\0';
	return (og_str);
}

void	handle_ptr(va_list *valist, int *ret)
{
	unsigned long	ptr_n;
	char			*ptr_s;

	ptr_n = va_arg(*valist, unsigned long long);
	if (ptr_n == 0)
	{
		*ret += 5;
		write(1, "(nil)", 5);
		return ;
	}
	ptr_s = make_hex_str(ptr_n);
	if (ptr_s == NULL)
		return ;
	write(1, "0x", 2);
	write(1, ptr_s, ft_strlen(ptr_s));
	*ret += (ft_strlen(ptr_s) + 2);
	free(ptr_s);
}

void	handle_di(va_list *valist, int *ret)
{
	long	n;
	int		neg;
	int		len;

	n = (long)va_arg(*valist, int);
	neg = (n < 0);
	ft_putnbr_fd(n, 1);
	n *= (1 + (n < 0) * -2);
	len = 1;
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	*ret += len + neg;
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
