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
