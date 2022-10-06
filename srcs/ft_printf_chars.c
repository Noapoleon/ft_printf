/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:32 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/02 21:58:26 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list *valist, int *ret)
{
	*ret += 1;
	ft_putchar_fd((char)va_arg(*valist, int), 1);
}

void	handle_str(va_list *valist, int *ret)
{
	char	*tmp;

	tmp = va_arg(*valist, char *);
	if (tmp == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	*ret += ft_strlen(tmp);
	ft_putstr_fd(tmp, 1);
}

void	handle_percent(int *ret)
{
	*ret += 1;
	write(1, "%", 1);
}
