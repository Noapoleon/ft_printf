/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:30:00 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/16 06:34:45 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_di(t_print *print, va_list valist)
{
	int		n;
	char	*tmp;

	n = va_arg(valist, int);
	tmp = ft_itoa(n);
	if (tmp == NULL)
		return (-1);
	if (fill_buf(print, tmp, -1) == -1)
		return (free(tmp), -1);
	return (free(tmp), 0);
}

int	hdl_u(t_print *print, va_list valist)
{
	unsigned int	n;
	char			*tmp;

	n = va_arg(valist, unsigned int);
	tmp = uitoa(n);
	if (tmp == NULL)
		return (-1);
	if (fill_buf(print, tmp, -1) == -1)
		return (free(tmp), -1);
	return (free(tmp), 0);
}
