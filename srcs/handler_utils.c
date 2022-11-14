/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:18 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 02:46:24 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_convs(t_print *print)
{
	char		*tmp;
	char		*end;

	reset_state(print);
	set_conv_state(print, &end);
	if (print->bad_s)
	{
		tmp = ft_substr(print->s, 0, end - print->s);
		print->ret += end - print->s;
	}
	else
		tmp = (print->handler_s)(print);
	if (tmp == NULL)
		return (NULL);
	print->s = end;
	return (tmp);
}

void	reset_state(t_print *print)
{
	print->flags_s = 0;
	print->conv_s = 0;
	print->bad_s = 0;
	print->handler_s = NULL;
}

void	set_conv_state(t_print *print, char **end)
{
	// CHANGE THIS FUNCTION TO HANDLING BONUSES
	static char	*(*handlers[])(t_print *print) = {hdl_c, hdl_s, hdl_p, hdl_di,
		hdl_di, hdl_u, hdl_x, hdl_x, hdl_ps};
	char	*i;

	print->conv_s = *(print->s + 1);
	i = ft_strchr(CONV_SET, print->conv_s);
	if (i == NULL)
		return ((void)(print->bad_s = 1));
	print->handler_s = handlers[i - CONV_SET];
	*end = print->s + 2;
}

