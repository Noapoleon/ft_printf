/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 04:41:12 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	init_print(t_print *print, const char *s, va_list *valist)
{
	// PROTECTED, NOT TESTED
	char	*tmp;

	print->s = (char *)s;
	print->valist = valist;
	print->ret = 0;
	tmp = ft_strdup("\0");
	if (tmp == NULL)
		return (-1);
	print->parts = malloc(sizeof(t_list));
	if (print->parts == NULL)
		return (free(tmp), -1);
	print->parts->content = tmp;
	return (0);
}

void	write_n_free(t_list **parts)
{
	// check if the free logic is good
	t_list	*curr;
	t_list	*tmp;

	curr = (*parts)->next; // dont forget first one is '\0'
	while (curr != NULL)
	{
		tmp = curr;
		if (write(OUT_FD, curr->content, ft_strlen(curr->content)) == -1)
			return ((void)ft_lstclear(&curr, free));
		curr = curr->next;
		free (tmp);
	}
}

int	make_output(t_print *print)
{
	// CHECK PROTECTION
	t_list	*curr;

	curr = print->parts;
	while (*(print->s))
	{
		if (*(print->s) == '%')
		{
			if (make_conv(print, curr) == -1)
				return (-1);
		}
		else
			if (make_str(print, curr) == -1)
				return (-1);
		curr = curr->next;
	}
	return (0);
}

int make_str(t_print *print, t_list *prev)
{
	// PROTECTED, NOT TESTED
	char	*end;
	char	*tmp;

	end = print->s;
	while (*end && *end != '%')
		++end;
	tmp = ft_substr(print->s, 0, end - print->s);
	if (tmp == NULL)
		return (-1);
	prev->next = ft_lstnew(tmp);
	if (prev->next == NULL)
		return (free(tmp), -1);
	print->ret += end - print->s;
	print->s = end;
	return (0);
}

int	make_conv(t_print *print, t_list *prev)
{
	// PROTECTED, NOT TESTED
	char	*tmp;

	tmp = handle_convs(print);
	if (tmp == NULL)
		return (-1);
	prev->next = ft_lstnew(tmp);
	if (prev->next == NULL)
		return (free(tmp), -1);
	return (0);
}
