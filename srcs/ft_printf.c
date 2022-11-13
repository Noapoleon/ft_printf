/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:46 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/12 19:20:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	int		ret;
	va_list	valist;
	t_list	*parts;

	ret = 0;
	va_start(valist, s);
	parts = init_parts();
	if ((parts == NULL) || (make_output(s, &valist, parts, &ret) == -1))
		return (-1); // free accordingly
	write_output(parts);
	va_end(valist);
	return (ret);
}
