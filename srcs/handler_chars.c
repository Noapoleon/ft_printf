/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:10 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:53:18 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hdl_c(t_print *print, va_list valist)
{
	char	c;
	char	*tmp;

	c = va_arg(valist, int);
	tmp = malloc(sizeof(char) * 2);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	print->ret += 1;
	return (tmp);
}

char	*hdl_s(t_print *print, va_list valist)
{
	char	*tmp;

	tmp = va_arg(valist, char *);
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(char) * 7);
		if (tmp == NULL)
			return (NULL);
		ft_strlcpy(tmp, "(null)", 7);
	}
	print->ret += ft_strlen(tmp);
	return (tmp);
}

char	*hdl_ps(t_print *print, va_list valist)
{
	char	*tmp;

	(void)valist;
	tmp = malloc(sizeof(char) * 2);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '%';
	tmp[1] = '\0';
	print->ret += 1;
	return (tmp);
}
