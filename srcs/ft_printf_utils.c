/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/14 18:38:32 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	init_print(t_print *print, const char *s)
{
	// PROTECTED, NOT TESTED
	char	*tmp;

	print->s = (char *)s;
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

void	write_n_free(t_list **parts, int fd)
{
	// check if the free logic is good
	t_list	*curr;
	t_list	*tmp;

	curr = (*parts)->next; // dont forget first one is '\0'
	while (curr != NULL)
	{
		tmp = curr;
		if (write(fd, curr->content, ft_strlen(curr->content)) == -1)
			return ((void)ft_lstclear(&curr, free));
		curr = curr->next;
		ft_lstdelone(tmp, free);
	}
	ft_lstdelone(*parts, free);
}

int	make_output(t_print *print, va_list valist)
{
	// CHECK PROTECTION
	t_list	*curr;

	curr = print->parts;
	while (*(print->s))
	{
		if (*(print->s) == '%')
		{
			if (make_conv(print, valist, curr) == -1)
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
	t_list	*new;

	end = print->s;
	while (*end && *end != '%')
		++end;
	tmp = ft_substr(print->s, 0, end - print->s);
	if (tmp == NULL)
		return (-1);
	new = ft_lstnew(tmp);
	if (new == NULL)
		return (free(tmp), -1);
	if (prev == NULL)
		print->parts = new;
	else
		prev->next = new;
	print->ret += end - print->s;
	print->s = end;
	return (0);
}

int	make_conv(t_print *print, va_list valist, t_list *prev)
{
	// PROTECTED, NOT TESTED
	char	*tmp;
	t_list	*new;

	tmp = handle_convs(print, valist);
	if (tmp == NULL)
		return (-1);
	new = ft_lstnew(tmp);
	if (new == NULL)
		return (free(tmp), -1);
	if (prev == NULL)
		print->parts = new;
	else
		prev->next = new;
	return (0);
}
