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

char	*hdl_c(t_print *print)
{
	char	c;
	char	*tmp;

	c = va_arg(*valist, char);
	tmp = malloc(sizeof(char) * 2);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

char	*hdl_s(t_print *print)
{
	char	*tmp;

	tmp = va_arg(*valist, char *);
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(char) * 7);
		if (tmp == NULL)
			return (NULL);
		strlcpy(tmp, "(null)", 7);
	}
	print->ret += ft_strlen(tmp);
	return (tmp);
}
