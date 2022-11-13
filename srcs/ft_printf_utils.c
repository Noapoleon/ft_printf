/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:53 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/12 21:11:14 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//static int	len_to_conv(const char *s)
//{
//	const char	*og_s;
//
//	og_s = s;
//	while (*s && *s != '%')
//		++s;
//	return (s - og_s);
//}

t_list	*init_parts()
{
	// already protected, not tested
	t_list	*beg;
	char	*tmp;

	tmp = ft_strdup("\0");
	if (tmp == NULL)
		return (-1);
	beg = ft_lstnew(tmp);
	if (beg == NULL)
		return (free(tmp), -1);
	return (0);
}

int	write_output(t_list *out)
{
	t_list	*curr;
	t_list	*tmp;

	//dont forget first one is '\0'
	curr = out->next; // the ->next is for the first struct whose content is '\0'
	while (curr != NULL)
	{
		tmp = curr;
		if (write(1, curr->content, ft_strlen(curr->content)))
			return (ft_lstclear(curr), -1);
		curr = curr->next;
		free (tmp);
	}
	return (0);
}

int	make_output(const char *s, va_list *valist, t_list *beg, int *ret)
{
	t_list *curr;

	curr = beg;
	while (*s)
	{
		if (*ss = '%')
			if (make_conv(&s, valist, &curr->next, ret) == -1)
				return (-1); // free accordingly
		else
			if (make_str(&s, &curr->next, ret) == -1)
				return (-1); // free accordingly

	}
	return (0);
}

int make_str(char **s, t_list **part, int *ret)
{
	// already protected, not tested
	char	*end;
	char	*tmp;

	end = *s;
	while (*end && *end != '%')
		++end;
	tmp = ft_substr(s, 0, end - s);
	if (tmp == NULL)
		return (-1);
	*part = ft_lstnew(tmp);
	if (*part == NULL)
		return (free(tmp), -1);
	*ret += end - s;
	*s = end;
	return (0);
}
