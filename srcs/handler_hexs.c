/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:59:56 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 03:02:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hdl_x(t_print *print)
{
	unsigned int	x;
	char			*tmp;

	x = va_arg(*(print->valist), unsigned int);
	tmp = make_hexstr(x, (print->conv_s == 'X'));
	if (tmp == NULL)
		return (NULL);
	print->ret += ft_strlen(tmp);
	return (tmp);
}

char	*hdl_p(t_print *print)
{
	size_t	x;
	char	*tmp;
	char	*old;

	x = va_arg(*(print->valist), size_t);
	tmp = make_hexstr(x, 0);
	if (tmp == NULL)
		return (NULL);
	old = tmp;
	tmp = ft_strjoin("0x", tmp);
	free(old);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

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
