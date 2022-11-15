/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/15 21:24:36 by nlegrand         ###   ########.fr       */
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


void	reset_state(t_print *print)
{
	print->conv_s = '\0';
	print->flags_s = 0;
	print->width_s = 0;
	print->preci_s = 0;
	print->handler_s = NULL;
	print->bad_s = 0;
}
int	get_flags(t_print *print, int **s)
{
	char *ss;
	char	*f;
	int		mask;

	ss = *s;
	while (*ss)
	{
		if (*ss == '\0')
			return (-1);
		f = ft_strchr(FLAG_SET, *ss);
		if (f == NULL)
			break ;
		mask = 1;
		mask <<= f - FLAG_SET;
		++ss;
	}
	*s = ss;
	return (0);
}

int	get_width(t_print *print, int **s)
{
	char *ss;

	ss = *s;
	print->width_s = atoi2(ss);
	if (print->width_s == -1)
		return (-1);
	while (ft_isdigit(*ss))
		++ss;
	if (*ss == '\0')
		return (-1);
	*s = ss;
	return (0);
}

int	get_preci(t_print *print, int **s)
{
	break ;
}

int	get_conv(t_print *print, int **s)
{
	// NEED TO ADD A HANDLER FOR BAD CONVERSIONS
	// SO THAT IT PRINTS THE PRECISION AS 0 IF IT'S AND IMPLICIT PRECISION
	// e.g.: %.[
	break ;
}

int	set_conv_state(t_print *print)
{
	// CHECK IF BAD CONVERSION AND NO CONVERSIONS ARE NECESSARY
	// BAD CONVERSION AND NO CONVERSION SHOULD HAVE DIFFERENT VALUES
	// BECAUSE YOU PRINT A "NO CONVERSION"
	// CHANGE THIS FUNCTION FOR HANDLING BONUSES
	//static int	(*handlers[])(t_print *print, va_list valist) =
	//{hdl_c, hdl_s, hdl_p, hdl_di, hdl_di, hdl_u, hdl_x, hdl_x, hdl_c};
	char	*s;
	char	*f;
	int		set;

	reset_state(print);
	s = print->s + 1;
	if (get_flags(print, &s) == -1)
		return (-1);
	if (get_width(print, &s) == -1)
		return (-1);
	// FOR THE WEIRD PRECISION BEHAVIOR PRINTING 0 WHEN CONVERSION IS WRONG YOU JUST NEED TO CHECK EXIT SET_CONV_STATE WITH BOTH PRINT->BAD_S AND PRINT->PRECI_S SET, if both are set then fill buff with the value in preci_s
	if (get_preci(print, &s) == -1)
		return (-1);
	if (*s == '.' && s++)
		print->preci_s = atoi2(s);
	while (ft_isdigit(s))
		++s;
//	if (*s == '\0')
//		return (();
	print->conv_s = *s;
	if (ft_strchr(CONV_SET, print->conv_s) == NULL)
		return (-1); // NOT TRUE FIX LATER

	//print->conv_s = *(print->s + 1);
	//i = ft_strchr(CONV_SET, print->conv_s);
	//if (i == NULL)
	//	return ((void)(print->bad_s = 1));
	//print->handler_s = handlers[i - CONV_SET];
	//print->s += 2; // THIS LINE SPECIFICALLY BUT WAY MORE THAN JUST THAT
}

void	print_state(t_print *print)
{
	// REMOVE THIS AFTER
	printf("print->conv_s ====> %c\n", print->conv_c);
	printf("print->flags_s ===> %d\n", print->flags_s);
	printf("print->bad_s =====> %d\n", print->bad_s);
	printf("print->width_s ===> %d\n", print->width_s);
	printf("print->pres_s ====> %d\n", print->preci_s);
}
