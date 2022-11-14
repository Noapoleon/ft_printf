/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:30:00 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:43:25 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hdl_di(t_print *print, va_list valist)
{
	int		n;
	char	*tmp;

	n = va_arg(valist, int);
	tmp = ft_itoa(n);
	if (tmp == NULL)
		return (NULL);
	print->ret += ft_strlen(tmp);
	return (tmp);
}

char	*hdl_u(t_print *print, va_list valist)
{
	unsigned int	n;
	char			*tmp;

	n = va_arg(valist, unsigned int);
	tmp = uitoa(n);
	if (tmp == NULL)
		return (NULL);
	print->ret += ft_strlen(tmp);
	return (tmp);
}

char	*uitoa(unsigned int n)
{
	long	pow;
	int		len_pow;
	char	*tmp;

	pow = 1;
	len_pow = 1;
	while ((n / pow) >= 10)
	{
		pow *= 10;
		++len_pow;
	}
	tmp = (char *)malloc(sizeof(char) * (len_pow + 1));
	if (tmp == NULL)
		return (NULL);
	len_pow = 0;
	while (pow > 0)
	{
		tmp[len_pow++] = '0' + ((n / pow) % 10);
		pow /= 10;
	}
	tmp[len_pow] = '\0';
	return (tmp);
}
