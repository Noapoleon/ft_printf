/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:18 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:42:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*make_hexstr(size_t dec, int caps)
{
	size_t	pow;
	int		len;
	char	*tmp;

	pow = 1;
	len = 1;
	while ((dec / pow) >= 16)
	{
		pow *= 16;
		++len;
	}
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	len = 0;
	while (pow > 0)
	{
		tmp[len] = *(HEX_SET + ((dec / pow) % 16));
		if (ft_isalpha(tmp[len]) && caps)
			tmp[len] -= 32;
		++len;
		pow /= 16;
	}
	tmp[len] = '\0';
	return (tmp);
}

char	*uitoa(unsigned int n)
{
	long	pow;
	int		len_pow;
	char	*tmp;

	pow = 1;
	len_pow = 1;
	while ((n / pow) >= 10)
	{
		pow *= 10;
		++len_pow;
	}
	tmp = (char *)malloc(sizeof(char) * (len_pow + 1));
	if (tmp == NULL)
		return (NULL);
	len_pow = 0;
	while (pow > 0)
	{
		tmp[len_pow++] = '0' + ((n / pow) % 10);
		pow /= 10;
	}
	tmp[len_pow] = '\0';
	return (tmp);
}
