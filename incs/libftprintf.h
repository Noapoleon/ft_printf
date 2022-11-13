/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:46:40 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/12 19:03:18 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#include <stdio.h>

# define CONVSET "cspdiuxX%"

int	ft_printf(const char *s, ...);
int	write_output(t_list *parts);
int	make_output(const char *s, va_list *valist, t_list *parts, int *ret);
int	make_str(char **s, t_list **part, int *ret);

// HANDLERS
int	handle_char(va_list *valist);
int	handle_str(va_list *valist);
int	handle_di(va_list *valist);
int	handle_uint(va_list *valist);
int	handle_ptr(va_list *valist);
int	handle_hex(va_list *valist, int caps);

#endif
