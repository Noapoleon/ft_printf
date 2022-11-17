#include "libftprintf.h"

int	set_conv_state(t_print *print)
{
	// CHECK IF BAD CONVERSION AND NO CONVERSIONS ARE NECESSARY
	// BAD CONVERSION AND NO CONVERSION SHOULD HAVE DIFFERENT VALUES
	// BECAUSE YOU PRINT A "NO CONVERSION"
	// CHANGE THIS FUNCTION FOR HANDLING BONUSES
	//static int	(*handlers[])(t_print *print, va_list valist) =
	//{hdl_c, hdl_s, hdl_p, hdl_di, hdl_di, hdl_u, hdl_x, hdl_x, hdl_c};
	char	*s;

	print_state(print, PRINT_RESET, NULL, -1);
	s = print->s + 1;
	if (get_flags(print, &s) == -1)
		return (-1);
	if (get_width(print, &s) == -1)
		return (-1);
	// DONT REMOVE YET:
	// FOR THE WEIRD PRECISION BEHAVIOR PRINTING 0 WHEN CONVERSION IS WRONG YOU
	// JUST NEED TO EXIT SET_CONV_STATE WITH BOTH PRINT->BAD_S (as -2) AND
	// PRINT->PRECI_S SET, if both are set then fill buff with the value in
	// preci_s. Then it can be handled in a dedicated handler. handler set in
	// get_conv
	// IMP NOTE: if conversion is wrong, flags are outputted in a weird order
	// and some of them are even not outputted, probably because of order or
	// priority (e.g.: 0 ignored if - is present)
	if (get_preci(print, &s) == -1)
		return (-1);
	if (get_conv(print, &s) == -1)
		return (-1);
	if (print->bad_s != 1)
		print->s = s;
//	output_state(print);
	return (0);
	// IF set_conv_state EXITS WITH -1 I SHOULD PRINT THE BUFFER AND STOP
	// ALSO EXIT PRINTF WITH -1

	//print->conv_s = *(print->s + 1);
	//i = ft_strchr(CONV_SET, print->conv_s);
	//if (i == NULL)
	//	return ((void)(print->bad_s = 1));
	//print->handler_s = handlers[i - CONV_SET];
}

int	get_flags(t_print *print, char **s)
{
	char *ss;
	char	*f;
	int		mask;

	ss = *s;
	while (*ss)
	{
		f = ft_strchr(FLAG_SET, *ss);
		if (f == NULL)
			break ;
		mask = 1;
		mask <<= f - FLAG_SET;
		print->flags_s |= mask;
		++ss;
	}
	if (*ss == '\0')
		return (-1);
	*s = ss;
	return (0);
}

int	get_width(t_print *print, char **s)
{
	char *ss;

	ss = *s;
	print->width_s = atoi_noof(ss);
	if (print->width_s == -1)
		return (-1);
	while (ft_isdigit(*ss))
		++ss;
	if (*ss == '\0')
		return (-1);
	*s = ss;
	return (0);
}

int	get_preci(t_print *print, char **s)
{
	char *ss;

	ss = *s;
	if (*ss != '.')
		return (0);
	++ss;
	print->preci_s = atoi_noof(ss);
	while (ft_isdigit(*ss))
		++ss;
	if (print->preci_s == -1 || *ss == 0)
		return (-1);
	*s = ss;
	return (0);
}

int	get_conv(t_print *print, char **s)
{
	// NEED TO ADD A HANDLER FOR BAD CONVERSIONS
	// SO THAT IT PRINTS THE PRECISION AS 0 IF IT'S AND IMPLICIT PRECISION
	// e.g.: %.[
	char	*ss;
	char	*c;
	static int	(*handlers[])(t_print *print, va_list valist) =
	{hdl_c, hdl_s, hdl_ps, hdl_p, hdl_di, hdl_di, hdl_u, hdl_x, hdl_x};
	int		mask;

	ss = *s;
	if (*ss == '\0')
		return (-1);
	c = ft_strchr(CONV_SET, *ss);
	if (c == NULL) // MIGHT NEED TO CHANGE THIS SO THAT IT MOVES THE PRINT->S AFTER THE BAD CONVERSION
	{
		print->bad_s = 1;
		print->handler_s = hdl_bad;
		return (0);
	}
	mask = 1;
	mask <<= c - CONV_SET;
	print->conv_s = mask;
	print->handler_s = handlers[c - CONV_SET];
	*s = ss + 1;
	return (0);
}
