#include "../includes/projet.h"

int	main(int ac, char **av)
{
	t_data	*d;

	if (init_start(&d, ac, av) < 0)
		return(error("main:: Initialization error"));
	return(0);
}
