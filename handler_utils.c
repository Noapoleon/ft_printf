/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:18 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/13 18:25:06 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*handle_convs(t_print *print)
{
	char		*tmp;
	char		*end;
	static int	(*handlers[])(t_print *print) = {hdl_c, hdl_s, hdl_p, hdl_d,
		hdl_i, hdl_u, hdl_x, hdl_X, hld_pp};

	reset_state(print);
	set_conv_state(print->s, &state, end);
	if (printf->state_bad)
	{
		tmp = ft_substr(*s, 0, end - print->s);
		print->ret += end - print->s;
	}
	else
	{
		tmp = handlers[ft_strchr(CONV_SET, print->conv_s
	}
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
}

void	set_conv_state(t_print *print, end)
{
	break ; //remove after
}
