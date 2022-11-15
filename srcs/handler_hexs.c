/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:59:56 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:54:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hdl_x(t_print *print, va_list valist)
{
	unsigned int	x;
	char			*tmp;

	x = va_arg(valist, unsigned int);
	tmp = make_hexstr(x, (print->conv_s == 'X'));
	if (tmp == NULL)
		return (NULL);
	print->ret += ft_strlen(tmp);
	return (tmp);
}

char	*hdl_p(t_print *print, va_list valist)
{
	size_t	x;
	char	*tmp;
	char	*old;

	x = va_arg(valist, size_t);
	tmp = make_hexstr(x, 0);
	if (tmp == NULL)
		return (NULL);
	old = tmp;
	tmp = ft_strjoin("0x", tmp);
	free(old);
	if (tmp == NULL)
		return (NULL);
	print->ret += ft_strlen(tmp);
	return (tmp);
}
