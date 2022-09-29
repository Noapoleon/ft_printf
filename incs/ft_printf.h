#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define CONV_SET "cspdiuxX%"

int		ft_printf(const char *s);
int		is_setchar(const char *set, const char c);
int		count_conversions(const char *s);
void	putconv(const char c);
size_t	len_to_conv(const char *s);
void	putaddr(void *addr);

#endif
