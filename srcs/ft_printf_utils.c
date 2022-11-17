/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/17 00:53:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_state(t_print *print, int mode, const char *s, int fd)
{
	if (mode == PRINT_INIT)
	{
		print->s = (char *)s;
		print->fd = fd;
		print->ret = 0;
		print->buf[0] = '\0';
		print->pos = 0;
	}
	print->conv_s = 0;
	print->flags_s = 0;
	print->width_s = 0;
	print->preci_s = -1;
	print->handler_s = NULL;
	print->bad_s = 0;
}

int	output_full(t_print *print)
{
	if (print->pos == PRINT_SIZE)
	{
		if (write(print->fd, print->buf, print->pos) == -1)
			return (-1);
		print->pos = 0;
	}
	return (0);
}

int	fill_buf(t_print *print, char *s, int n)
{
	int	len;

	len = 0;
	while ((n < 0 && s[len]) || (n > 0 && len < n))
	{
		if (n == -2 && s[len] == '%')
			break ;
		print->buf[print->pos++] = s[len++];
		if (output_full(print) == -1)
			return (-1);
	}
	// CHECK IF n == 0 HAS A USE
	print->ret += len;
	if (s == print->s)
		print->s += len;
	return (0);
}
//int fill_buf(t_print *print, char *s, int n) // NOT TESTED
//{
//	// if src == print->s dont put anything other than 0 for size
//	// actually it's fine with some stuff like 's' conversion
//	// will check if true for other ones as well
//	int			len;
//	const int	stop_ps = (n == -2);
//
//	len = 0;
//	// s[len] in n>0 was added to fix a problem with s conversion, need to check if that breaks anything
//	while ((n > 0 && len != n && s[len]) || (n <= -1 && s[len])) // might need to change n!=0 for precision flags and s conv {
//	{
//		if (stop_ps && s[len] == '%')
//			break ;
//		if (print->pos == PRINT_SIZE)
//		{
//			print->pos = 0;
//			if (write(print->fd, s, PRINT_SIZE) == -1)
//				return (-1);
//		}
//		print->buf[print->pos++] = s[len++];
//	}
//	print->ret += len;
//	if (s == print->s)
//		print->s += len;
//	return (0);
//}

int	atoi_noof(const char *nptr)
{
	long	nb;
	int		sign;

	nb = 0;
	while (*nptr && (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == ' ')))
		++nptr;
	sign = 1;
	if ((*nptr == '-') || (*nptr == '+'))
		if (*nptr++ == '-')
			sign = -1;
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		nb = (nb * 10) + (*nptr++ - 48);
		if (nb > INT_MAX && sign == 1)
			return (-1);
		if (nb > (long)INT_MAX + 1 && sign == -1)
			return (0);
	}
	return (sign * (int)nb);
}

int	maxi(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int mini(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	output_state(t_print *print)
{
	// REMOVE THIS AFTER
	printf("print->conv_s ====> %d\n", print->conv_s);
	printf("printf->conv_s char => %c\n", conv_char(print));
	printf("print->flags_s ===> %d\n", print->flags_s);
	printf("print->bad_s =====> %d\n", print->bad_s);
	printf("print->width_s ===> %d\n", print->width_s);
	printf("print->pres_s ====> %d\n", print->preci_s);
	printf("FLAGS:\n");
	if (print->flags_s & FLAG_MINUS)
		printf("- '-' minus\n");
	if (print->flags_s & FLAG_ZERO)
		printf("- '0' zero\n");
	if (print->flags_s & FLAG_HASH)
		printf("- '#' hash\n");
	if (print->flags_s & FLAG_SPACE)
		printf("- ' ' space\n");
	if (print->flags_s & FLAG_PLUS)
		printf("- '+' plus\n");
}
