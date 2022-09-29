/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:21:29 by nlegrand          #+#    #+#             */
/*   Updated: 2022/09/29 18:38:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	if (ac < 2)
		return (printf("Wrong number of arguments.\n"), 0);
	//printf("addr av -> %p\n", av);
	if (ft_printf(av[1]) == 1)
		fprintf(stderr, "ft_printf failed.");
	return (0);
}
