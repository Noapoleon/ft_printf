/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:59:56 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/16 14:56:04 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_x(t_print *print, va_list valist)
{
	unsigned int	x;
	char			*tmp;

	x = va_arg(valist, unsigned int);
	tmp = make_hexstr(x, (conv_char(print) == 'X'));
	if (tmp == NULL)
		return (-1);
	if (fill_buf(print, tmp, -1) == -1)
		return (free(tmp), -1);
	return (free(tmp), 0);
}

int	hdl_p(t_print *print, va_list valist)
{
	size_t	x;
	char	*tmp;
	char	*old;

	x = va_arg(valist, size_t);
	if (x == 0)
		return (fill_buf(print, "(nil)", -1));
	tmp = make_hexstr(x, 0);
	if (tmp == NULL)
		return (-1);
	old = tmp;
	tmp = ft_strjoin("0x", tmp);
	free(old);
	if (tmp == NULL)
		return (-1);
	if (fill_buf(print, tmp, -1) == -1)
		return (free(tmp), -1);
	return (free(tmp), 0);
}
