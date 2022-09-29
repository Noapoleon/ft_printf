/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:32 by nlegrand          #+#    #+#             */
/*   Updated: 2022/09/29 17:49:45 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putptr(void *addr)
{
	unsigned long	addr_n;
	char			addr_s[15];
	unsigned int	i;

	addr_n = (unsigned long long)addr;
	addr_s[0] = '0';
	addr_s[1] = 'x';
	addr_s[14] = '\0';
	i = 13;
	while (i >= 2)
	{
		if ((addr_n % 16) < 10)
			addr_s[i] = '0' + (addr_n % 16);
		else
			addr_s[i] = 'a' + (addr_n % 16 - 10);
		addr_n /= 16;
		--i;
	}
	ft_putstr_fd(addr_s, 1);
}
