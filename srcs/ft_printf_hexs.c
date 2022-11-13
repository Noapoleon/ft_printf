/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:59:56 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/12 16:53:03 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*make_hexstr(size_t dec)
{
	char	*
	int		len;
	char	tmp[16];
	char	*ptr;

	len = neg;
	while (n >= 10)
	{
		tmp[len++] = n % 10 + 48;
		n /= 10;
	}
	tmp[len++] = n % 10 + 48;
	p tr = tmp + len - 1;
	while ((tmp + neg) < ptr)
	{
		n = tmp[neg];
		tmp[neg++] = *ptr;
		*ptr-- = (char)n;
	}
	write(1, tmp, len);
}

int	handle_hex_lc(va_list *valist)
{

	return (len);
}

int	handle_hex_uc(va_list *valist)
{
	
	return (len);
}

int	handle_ptr(va_list *valist)
{
	size_t	ptr_n;
	char	*ptr_s;
	int		len;

	ptr_n = va_arg(*valist, size_t);
	if (ptr_n == 0)
	{
		*ret += 5;
		write(1, "(nil)", 5);
		return ;
	}
	ptr_s = make_hex_str(ptr_n);
	if (ptr_s == NULL)
		return ;
	write(1, "0x", 2);
	write(1, ptr_s, ft_strlen(ptr_s));
	*ret += (ft_strlen(ptr_s) + 2);
	free(ptr_s);
}
