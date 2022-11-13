/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:18 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/13 18:57:49 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*handle_convs(t_print *print)
{
	char		*tmp;
	char		*end;

	reset_state(print);
	set_conv_state(print->s, &state, end);
	if (printf->bad_s)
	{
		tmp = ft_substr(*s, 0, end - print->s);
		print->ret += end - print->s;
	}
	else
		tmp = print->handler_s;
	if (tmp == NULL)
		return (NULL);
	*s = end;
	return (tmp);
}

void	reset_state(t_print *print)
{
	print->flags_s = 0;
	print->conv_s = 0;
	print->bad_s = 0;
	print->handlers = NULL;
}

void	set_conv_state(t_print *print, end)
{
	// CHANGE THIS FUNCTION TO HANDLING BONUSES
	static char	*(*handlers[])(t_print *print) = {hdl_c, hdl_s, hdl_p, hdl_d,
		hdl_i, hdl_u, hdl_x, hdl_X, hld_pp};
	int			i;

	print->conv_s = *(s + 1);
	i = ft_strchr(CONV_SET, print->conv_s);
	if (i == NULL)
		return ((void)(print->bad_s = 1));
	print->handler = handlers[i - CONV_SET];
}
