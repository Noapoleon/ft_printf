/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:32 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/01 17:28:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putptr(void *ptr)
{
	unsigned long	ptr_n;
	char			ptr_s[15];
	unsigned int	i;

	ptr_n = (unsigned long long)ptr;
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

void	puthex(unsigned int n, int caps)
{
	unsigned long	nn;
	unsigned long	pow;
	char			tmp;

	nn = (unsigned long)n;
	pow = 1;
	while ((nn / pow) >= 16)
		pow *= 16;
	while (pow > 0)
	{
		if (((nn / pow) % 16) < 10)
			tmp = '0' + ((nn / pow) % 16);
		else
			tmp = 'a' + ((nn / pow) % 16 - 10) - (caps * 32);
		pow /= 16;
		write(1, &tmp, 1);
	}
}

void	putuint(unsigned int n)
{
	long	nn;
	long	pow;
	char	tmp;

	nn = (long)n;
	pow = 1;
	while ((nn / pow) >= 10)
		pow *= 10;
	while (pow > 0)
	{
		tmp = '0' + ((nn / pow) % 10);
		write(1, &tmp, 1);
		pow /= 10;
	}
}

// putuint
