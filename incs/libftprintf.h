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

# ifndef OUTFD
#  define OUT_FD 1
# endif
# define CONV_SET "cspdiuxX%"
# define HEX_SET "0123456789abcdef"

typedef struct s_print t_print;
struct s_print
{
	char	*s;
	int		ret;
	t_list	*parts;
	int		flags_s;
	char	conv_s;
	int		bad_s;
	char	*(*handler_s)(t_print *, va_list);
};

int	ft_printf(const char *s, ...);
int	w_vdprintf(int fd, const char *s, va_list valist);

// PRINTF UTILS
int		init_print(t_print *print, const char *s);
int		make_output(t_print *print, va_list valist);
int		make_str(t_print *print, t_list *curr);
int		make_conv(t_print *print, va_list valist, t_list *curr);
void	write_n_free(t_list **parts, int fd);

// HANDLER
char	*handle_convs(t_print *print, va_list valist);
void	reset_state(t_print *print);
void	set_conv_state(t_print *print, char **end);
char	*make_hexstr(size_t dec, int caps);
char	*uitoa(unsigned int n);
char	*hdl_c(t_print *print, va_list valist);
char	*hdl_s(t_print *print, va_list valist);
char	*hdl_p(t_print *print, va_list valist);
char	*hdl_di(t_print *print, va_list valist);
char	*hdl_u(t_print *print, va_list valist);
char	*hdl_x(t_print *print, va_list valist);
char	*hdl_ps(t_print *print, va_list valist);

#endif
