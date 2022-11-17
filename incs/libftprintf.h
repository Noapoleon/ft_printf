/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:46:40 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 22:52:35 by nlegrand         ###   ########.fr       */
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
# define PRINT_INIT 0
# define PRINT_RESET 1
# define SET_CONV "cs%pdiuxX"
# define SET_FLAG "-0# +"
# define SET_HEX "0123456789abcdef"
# define STR_NULL "(null)"
# define STR_NIL "(nil)"
# define STR_ZERO "\0"
# define PREF_XL "0x"
# define PREF_XU "0X"
# define PREF_PLUS "+"
# define PREF_MINUS "-"
# define PREF_SPACE " "

// CONV MASKS
# define CM_C 1
# define CM_S 2
# define CM_PS 4
# define CM_P 8
# define CM_D 16
# define CM_I 32
# define CM_U 64
# define CM_X 128
# define CM_XX 256

// FLAG MASKS
# define FM_MINUS 1
# define FM_ZERO 2
# define FM_HASH 4
# define FM_SPACE 8
# define FM_PLUS 16

typedef struct s_print	t_print;
struct s_print
{
	char	*s;
	int		fd;
	int		ret;
	char	buf[PRINT_SIZE];
	int		pos;
	int		convi;
	char	convc;
	int		flags;
	int		width;
	int		preci;
	int		(*handler)(t_print *, va_list);
	int		bad;
};

// MAIN
int		ft_printf(const char *s, ...);
int		w_vdprintf(int fd, const char *s, va_list valist);

// UTILS
void	set_state(t_print *print, int mode, const char *s, int fd);
int		fill_buf(t_print *print, char *s, int size);
int		atoi_safe(const char *nptr);
int		maxi(int a, int b);
int		mini(int a, int b);

// CONV PARSER & UTILS
int		set_conv_state(t_print *print);
int		get_flags(t_print *print, char **s);
int		get_width(t_print *print, char **s);
int		get_preci(t_print *print, char **s);
int		get_conv(t_print *print, char **s);

// HANDLERS & UTILS
int		hdl_c(t_print *print, va_list valist);
int		hdl_s(t_print *print, va_list valist);
int		hdl_p(t_print *print, va_list valist);
int		hdl_di(t_print *print, va_list valist);
int		hdl_u(t_print *print, va_list valist);
int		hdl_x(t_print *print, va_list valist);
int		hdl_ps(t_print *print, va_list valist);
void	get_hexstr(char *x, size_t n, int caps);
void	get_diustr(char *x, long n);
char	conv_char(t_print *print);
int		hdl_bad(t_print *print, va_list valist);

// FIELD UTILS
void	init_field(t_print *print, char *field, int len_field);
void	set_field_str(t_print *print, char *field, char *s, int len); // maybe change len to max
int		set_field_hex(t_print *print, char *field, char *x, int max);
int		set_field_diu(t_print *print, char *field, char *x, int max);

#endif
