#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	if (ac < 2)
		return (printf("wrong arguments, fool!\n"));
	fprintf(stderr, "printf ----> " "hello %s lol %s ok %s %%$\n", av[1], (char *)0, av[3]);
	ft_printf("ft_printf -> " "hello %s lol %s ok %s %%$\n", av[1], (char *)0, av[3]);
//	printf("printf ----> " av[1], av[2], av[3], av[4]);
//	ft_printf("ft_printf -> " av[1], av[2], av[3], av[4]);
	return (0);
}
