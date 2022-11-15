#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "nl_time.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*null_str = NULL;
	int		x = 42;

	if (ac < 2)
		return (printf("wrong arguments, fool!\n"));
	fprintf(stderr, "printf ----> ");
	nl_time(NLT_START);
	printf("%s %d", av[1], x);
	nl_time(NLT_MICRO | NLT_PRINT);

	fprintf(stderr, "\nft_printf -> ");
	nl_time(NLT_START);
	ft_printf("%s %d", av[1], x);
	nl_time(NLT_MICRO | NLT_PRINT);
	//ft_printf("%s", NULL);
//	fprintf(stderr, "printf ----> " "hello %s lol %s ok %s %%$\n", av[1], (char *)0, av[3]);
//	ft_printf("ft_printf -> " "hello %s lol %s ok %s %%$\n", av[1], (char *)0, av[3]);
//	printf("printf ----> " av[1], av[2], av[3], av[4]);
//	ft_printf("ft_printf -> " av[1], av[2], av[3], av[4]);
	return (0);
}
