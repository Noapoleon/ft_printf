/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:21:29 by nlegrand          #+#    #+#             */
/*   Updated: 2022/10/02 21:51:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//char str[] = "hello %c little %s man %p with %d no %i clock %u lol %x what %X you %% %% %% want %d veteran.\n";
	int ret;

	//printf("conv count = %d\n", count_conversions(str));
	//ft_printf(str, '$', "lalalalalala", av, 42, -69, 10, 255, 16777215, 1337);
	
	ret = printf("%d\n", -1);
	printf("ret -> %d\n", ret);
	ret = ft_printf("%d\n", -1);
	ft_printf("ret -> %d\n", ret);
	return (0);
}
