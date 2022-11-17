/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:46:40 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 01:51:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#include <stdio.h>

// SETTINGS
# ifndef PRINT_FD
#  define PRINT_FD 1
# endif
# ifndef PRINT_SIZE
#  define PRINT_SIZE 1024
# endif

// UTILITY DEFINES
# define CONV_SET "cs%pdiuxX"
# define FLAG_SET "-0# +"
# define HEX_SET "0123456789abcdef"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"
# define ZERO_STR "\0"

// CONV MASKS
# define CONV_C 1
# define CONV_S 2
# define CONV_PS 4
# define CONV_P 8
# define CONV_D 16
# define CONV_I 32
# define CONV_U 64
# define CONV_X 128
# define CONV_XX 256

// FLAG MASKS
# define FLAG_MINUS 1
# define FLAG_ZERO 2
# define FLAG_HASH 4
# define FLAG_SPACE 8
# define FLAG_PLUS 16

// STATE FLAGS
# define PRINT_INIT 0
# define PRINT_RESET 1

typedef struct s_print t_print;
struct s_print
{
	char	*s;
	int		fd;
	int		ret;
	char	buf[PRINT_SIZE];
	int		pos;
	int		conv_s;
	int		flags_s;
	int		width_s;
	int		preci_s;
	int		(*handler_s)(t_print *, va_list);
	int		bad_s;
};

int	ft_printf(const char *s, ...);
int	w_vdprintf(int fd, const char *s, va_list valist);

// UTILS
void	print_state(t_print *print, int mode, const char *s, int fd);
int		fill_buf(t_print *print, char *s, int size);
int		atoi_noof(const char *nptr);
int		maxi(int a, int b);
int		mini(int a, int b);

// FIELD UTILS
void	init_field(t_print *print, char *field, int len_field);
void	set_field_str(t_print *print, char *field, char *s, int len);

// CONV PARSER & UTILS
int		set_conv_state(t_print *print);
int		get_flags(t_print *print, char **s);
int		get_width(t_print *print, char **s);
int		get_preci(t_print *print, char **s);
int		get_conv(t_print *print, char **s);

// HANDLERS & HANDLER UTILS
char	*make_hexstr(size_t dec, int caps);
char	*uitoa(unsigned int n);
char	conv_char(t_print *print);
int		hdl_c(t_print *print, va_list valist);
int		hdl_s(t_print *print, va_list valist);
int		hdl_p(t_print *print, va_list valist);
int		hdl_di(t_print *print, va_list valist);
int		hdl_u(t_print *print, va_list valist);
int		hdl_x(t_print *print, va_list valist);
int		hdl_ps(t_print *print, va_list valist);
int		hdl_bad(t_print *print, va_list valist);

// REMOVE LATER
void	output_state(t_print *print);

#endif
