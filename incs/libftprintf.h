/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:46:40 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:49:04 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// SETTINGS
# ifndef PRINT_FD
#  define PRINT_FD 1
# endif
# ifndef PRINT_SIZE
#  define PRINT_SIZE 1024
# endif

// UTILITY DEFINES
# define CONV_SET "cspdiuxX%"
# define HEX_SET "0123456789abcdef"

typedef struct s_print t_print;
struct s_print
{
	char	*s;
	int		fd;
	int		ret;
	char	buf[PRINT_SIZE];
	int		pos;
	char	conv_s;
	int		flags_s;
	int		(*handler_s)(t_print *, va_list);
	int		bad_s;
};

int	ft_printf(const char *s, ...);
int	w_vdprintf(int fd, const char *s, va_list valist);

// UTILS
void	init_print(t_print *print, const char *s, int fd);
int		fill_buf(t_print *print, char *s, int size);
int		put_conv(t_print *print, va_list valist);
void	set_conv_state(t_print *print);

// HANDLERS & HANDLER UTILS
char	*make_hexstr(size_t dec, int caps);
char	*uitoa(unsigned int n);
int		hdl_c(t_print *print, va_list valist);
int		hdl_s(t_print *print, va_list valist);
int		hdl_p(t_print *print, va_list valist);
int		hdl_di(t_print *print, va_list valist);
int		hdl_u(t_print *print, va_list valist);
int		hdl_x(t_print *print, va_list valist);
int		hdl_ps(t_print *print, va_list valist);

#endif
