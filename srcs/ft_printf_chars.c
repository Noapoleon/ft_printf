/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:10 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/12 14:12:57 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hdl_char(va_list *valist)
{
	char	c;

	c = va_arg(*valist, char);
	write(1, c, 1);
	return (1);
}

int	hdl_str(va_list *valist)
{
	char	*s;
	int		len;

	s = va_arg(*valist, char *);
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
