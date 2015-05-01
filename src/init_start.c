#include "../includes/projet.h"

int	init_start(t_data **d, int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac < 2)
		return(error("init_start:: Require 2 args minimum"));
	*d = get_data();
	if (NULL == d)
		return (error("init_start:: t_data init is NULL, malloc failed"));
	if (open_log(*d) < 0)
		return (error("init_start:: Open_log error"));
	return (0);
}
