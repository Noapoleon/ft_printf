/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:46:40 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/13 18:53:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#include <stdio.h>

# define CONV_SET "cspdiuxX%"

typedef struct s_print
{
	char	*s;
	va_list	*valist;
	int		ret;
	t_list	parts;
	int		flags_s;
	char	conv_s;
	int		bad_s;
	char	(*handler);

}	t_print;

int	ft_printf(const char *s, ...);

// UTILS
t_print	*init_print(t_print *print, const char *s, va_list *valist)
int		write_output(t_list *parts);
int		make_output(print);
int		make_str(print, t_list *curr);
int		make_conv(print, t_list *curr);

// HANDLER
char	*hdl_c(t_print *print);
char	*hdl_s(t_print *print);
char	*hdl_p(t_print *print);
char	*hdl_d(t_print *print);
char	*hdl_i(t_print *print);
char	*hdl_u(t_print *print);
char	*hdl_x(t_print *print);
char	*hdl_X(t_print *print);
char	*hdl_%(t_print *print);

#endif
