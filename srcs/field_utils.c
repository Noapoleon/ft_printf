/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:00:28 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/18 12:50:45 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// disables overridden flags and sets prefix
void	set_compat(t_print *print)
{
	const char	c = print->convc;
	const int	f = print->flags;

	if (f & FM_PLUS)
		print->flags &= ~FM_SPACE;
	if (f & FM_MINUS || print->preci != -1)
		print->flags &= ~FM_ZERO;
	if (c == 'p')
		print->pref = PREF_XL;
	if (c == 'x' && f & FM_HASH)
		print->pref = PREF_XL;
	else if (c == 'X' && f & FM_HASH)
		print->pref = PREF_XU;
	else if (c == 'd' || c == 'i')
	{
		if (print->pref[0] != '-' && f & FM_PLUS)
			print->pref = PREF_PLUS;
		else if (print->pref[0] != '-' && f & FM_SPACE)
			print->pref = PREF_SPACE;
	}
	if ((f & FM_ZERO && print->preci == -1) || print->width <= print->preci)
		print->fillc = '0';
}

void	set_field_str(t_print *print, char *field, char *s, int len)
{
	const int	w = print->width;
	const int	p = print->preci;
	int			i;
	int			n;

	field[w] = '\0';
	if (print->flags & FM_MINUS)
		i = 0;
	else
		i = w - ((p == -1) * len) - ((p != -1) * p);
	n = 0;
	while (s[n] && i < w && (n != p))
		field[i++] = s[n++];
}

int	set_field_hex(t_print *print, char *field, char *x, int max)
{ // add support for (null)
	const int	f = print->flags;
	int			len;
	int			pdiff;

	pdiff = print->preci - ft_strlen(x);
	pdiff *= (pdiff >= 0);
	if (x[0] == '0' && print->preci == 0)
	{ // might need to change to so that it doesn't print the prefix sometimes, LOOK INTO IT
		ft_memcpy(field + ((f & FM_MINUS) == 0) * (max - 1), print->pref,
				ft_strlen(print->pref));
		return (fill_buf(print, field, -1));
	}
	len = max - comb_len(x, print->pref) - pdiff;
	len *= ((f & FM_MINUS) == 0);
	ft_memcpy(field + len * ((f & FM_ZERO) == 0)
			, print->pref, ft_strlen(print->pref));
	len += ft_strlen(print->pref);
	ft_memset(field + len, '0', pdiff);
	len += pdiff;
	ft_memcpy(field + len, x, ft_strlen(x));
	return (fill_buf(print, field, -1));
}
//int	set_field_hex(t_print *print, char *field, char *x, int max)
//{
//	const int	f = print->flags;
//	const int	p = print->preci;
//	int			len;
//	int			pdiff;
//
//	pdiff = print->preci - ft_strlen(x);
//	pdiff *= (pdiff >= 0);
//	len = max - ((pdiff > 0) * pdiff) - (int)ft_strlen(x)
//		- ((print->convc != 'p' && f & FM_HASH) * 2);
//	if (f & FM_MINUS)
//		len = 0;
//	if (f & FM_HASH && print->convc != 'p')
//	{
//		ft_memcpy(field + len, pre, 2);
//		len += 2;
//	}
//	if (pdiff > 0)
//	{
//		ft_memset(field + len, '0', pdiff);
//		len += pdiff;
//	}
//	ft_memcpy(field + len, x, ft_strlen(x));
//	return (fill_buf(print, field, -1));
//}

int	set_field_diu(t_print *print, char *field, char *x, int max)
{
	const int	f = print->flags;
	int			len;
	int			pdiff;

	pdiff = print->preci - ft_strlen(x);
	pdiff *= (pdiff >= 0);
	if (x[0] == '0' && print->preci == 0)
	{
		ft_memcpy(field + ((f & FM_MINUS) == 0) * (max - 1), print->pref,
				ft_strlen(print->pref));
		return (fill_buf(print, field, -1));
	}
	len = max - comb_len(x, print->pref) - pdiff;
	len *= ((f & FM_MINUS) == 0);
	ft_memcpy(field + len * ((f & FM_ZERO) == 0)
			, print->pref, ft_strlen(print->pref));
	len += ft_strlen(print->pref);
	ft_memset(field + len, '0', pdiff);
	len += pdiff;
	ft_memcpy(field + len, x, ft_strlen(x));
	return (fill_buf(print, field, -1));
}
