#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define CONV_SET "cspdiuxX%"

int		ft_printf(const char *s, ...);
int		is_setchar(const char *set, const char c);
int		count_conversions(const char *s);
void	putconv(const char c, va_list *valist, int *ret);
size_t	len_to_conv(const char *s);
void	handle_char(va_list *valist, int *ret);
void	handle_str(va_list *valist, int *ret);
void	handle_ptr(va_list *valist, int *ret);
void	handle_di(va_list *valist, int *ret);
void	handle_uint(va_list *valist, int *ret);
void	handle_hex(int caps, va_list *valist, int *ret);
void	handle_percent(int *ret);

#endif
