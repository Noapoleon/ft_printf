/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:00:28 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 01:50:44 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_field(t_print *print, char *field, int len_field)
{
	const int	f = print->flags_s;

	field[len_field] = '\0';
	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS) && print->conv_s >= CONV_P)
		ft_memset(field, '0', len_field);
	else
		ft_memset(field, ' ', len_field);
}

void	set_field_str(t_print *print, char *field, char *s, int len)
{
	const int	w = print->width_s;
	const int	p = print->preci_s;
	int			i;
	int			n;

	field[w] = '\0';
	if (print->flags_s & FLAG_MINUS)
		i = 0;
	else
		i = w - ((p == -1) * len) - ((p != -1) * p);
	n = 0;
	while (s[n] && i < w && (n != p))
		field[i++] = s[n++];
}
