/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:30:00 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/12 16:09:44 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_di(va_list *valist)
{
	long	n;
	char	*tmp;

	n = va_arg(*valist, int);
	tmp = itoa(n);
	if (tmp == NULL)
		return (NULL);
	print->ret += ft_strlen(tmp);
	return (tmp);
}


int	hdl_uint(va_list *valist)
{
	long	nn;
	int		neg;
	int		len;
	char	tmp[11];
	char	*ptr;

	nn = va_arg(*valist, unsigned int);
	tmp[0] = '-';
	len = neg;
	while (nn >= 10)
	{
		tmp[len++] = nn % 10 + 48;
		nn /= 10;
	}
	tmp[len++] = nn % 10 + 48;
	ptr = tmp + len - 1;
	while ((tmp + neg) < ptr)
	{
		nn = tmp[neg];
		tmp[neg++] = *ptr;
		*ptr-- = (char)nn;
	}
	write(1, tmp, len);
}
