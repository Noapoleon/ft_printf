#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char ** av)
{
	(void)ac;
	(void)av;

	if (ac != 2)
		return (printf("wrong arguments, fool!\n"));
	ft_printf("hello %d\n", atoi(av[1]));
	printf("hello %d\n", atoi(av[1]));
	return (0);
}
