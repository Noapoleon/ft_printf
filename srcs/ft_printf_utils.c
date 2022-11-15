/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:38:32 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_print(t_print *print, const char *s, int fd)
{
	print->s = (char *)s;
	print->fd = fd;
	print->ret = 0;
	print->buf[0] = '\0';
	print->pos = 0;
	print->conv_s = '\0';
	print->flags_s = 0;
	print->handler_s = NULL;
	print->bad_s = 0;
}

int fill_buf(t_print *print, char *s, int n) // NOT TESTED
{
	// if src == print->s dont put anything other than 0 for size
	// actually it's fine with some stuff like 's' conversion
	// will check if true for other ones as well
	int		len;

	len = 0;
	while ((s[len] && (s[len] != '%' || n == -1)) || (n != 0 && len < n))
	{
		if (print->pos == PRINT_SIZE)
		{
			print->pos = 0;
			if (write(print->fd, s, PRINT_SIZE) == -1)
				return (-1);
		}
		print->buf[print->pos++] = s[len++];
	}
	print->ret += len;
	if (s == print->s)
		print->s += len;
	return (0);
}
// DONT REMOVE THIS COMMENT YET
// IF NEEDED SAVE INTO A FILE BECAUSE IT'S NOT PRESENT ON OTHER BRANCHES
//int fill_buf(t_print *print)
//{
//	// NOT TESTED
//	int		len;
//	char	*s;
//
//	s = print->s;
//	len = 0;
//	while (s[len] && (s[len] != '%'))
//	{
//		if (print->pos == PRINT_SIZE)
//		{
//			print->pos = 0;
//			if (write(PRINT_FD, s, PRINT_SIZE) == -1)
//				return (-1);
//		}
//		print->buf[print->pos++] = s[len++];
//	}
//	print->ret += len;
//	print->s = s;
//	return (0);
//}

void	set_conv_state(t_print *print)
{
	// CHANGE THIS FUNCTION FOR HANDLING BONUSES
	static int	(*handlers[])(t_print *print, va_list valist) =
	{hdl_c, hdl_s, hdl_p, hdl_di, hdl_di, hdl_u, hdl_x, hdl_x, hdl_ps};
	char	*i;

	print->conv_s = *(print->s + 1);
	i = ft_strchr(CONV_SET, print->conv_s);
	if (i == NULL)
		return ((void)(print->bad_s = 1));
	print->handler_s = handlers[i - CONV_SET];
	print->s += 2; // THIS LINE SPECIFICALLY BUT WAY MORE THAN JUST THAT
}
