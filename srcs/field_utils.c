/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:00:28 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 22:52:24 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//void	init_field(t_print *print, char *field, int len_field, char c)
//{
//	const int	f = print->flags_s;
//
//	field[len_field] = '\0';
//	if ((f & F_ZERO) && !(f & F_MINUS) && print->conv_s >= CONV_P)
//		ft_memset(field, '0', len_field);
//	else
//		ft_memset(field, ' ', len_field);
//}

void	set_field_str(t_print *print, char *field, char *s, int len)
{
	const int	w = print->width_s;
	const int	p = print->preci_s;
	int			i;
	int			n;

	field[w] = '\0';
	if (print->flags_s & F_MINUS)
		i = 0;
	else
		i = w - ((p == -1) * len) - ((p != -1) * p);
	n = 0;
	while (s[n] && i < w && (n != p))
		field[i++] = s[n++];
}

int	set_field_hex(t_print *print, char *field, char *x, int max)
{
	const int	f = print->flags_s;
	const int	p = print->preci_s;
	int			len;
	const int	pdiff = p - ft_strlen(x);
	char		*pre;

	pre = ALT_L;
	if (conv_char(print) == 'X')
		pre = ALT_U;
	len = max - ((pdiff > 0) * pdiff) - (int)ft_strlen(x)
		- ((conv_char(print) != 'p' && f & F_HASH) * 2);
	if (f & F_MINUS)
		len = 0;
	if (f & F_HASH && conv_char(print) != 'p')
	{
		ft_memcpy(field + len, pre, 2);
		len += 2;
	}
	if (pdiff > 0)
	{
		ft_memset(field + len, '0', pdiff);
		len += pdiff;
	}
	ft_memcpy(field + len, x, ft_strlen(x));
	return (fill_buf(print, field, -1));
}

int	set_field_diu(t_print *print, char *field, char *x, int max)
{
	const int	f = print->flags_s;
	const int	p = print->preci_s;
	int			len;
	const int	pdiff = p - ft_strlen(x);

	len = max - ((pdiff > 0) * pdiff) - (int)ft_strlen(x);
	if (f & F_MINUS)
		len = 0;
	if (pdiff > 0)
	{
		ft_memset(field + len, '0', pdiff);
		len += pdiff;
	}
	ft_memcpy(field + len, x, ft_strlen(x));
	return (fill_buf(print, field, -1));
}

char	*get_prefix(t_print *print, char c) 
{
   	// potential for simplifying hex functions by giving STR_ZERO
	// depending on flags
	const int	f = print->flags;
	if (print->convc == 'x')
		return (PREF_XL);
	if (print->convc == 'X')
		return (PREF_XU);
	if (print->convc == 'd' || print->convc == 'i')
	{
		if (f & FM_PLUS && c != '-')
			return (PREF_PLUS);
		if (f & FM_PLUS && c == '-')
			return (PREF_MINUS);
		if (f & FM_SPACE && c != '-')
			return (PREF_SPACE);
		if (f & FM_SPACE && c == '-')
			return (STR_ZERO);
	}
}
