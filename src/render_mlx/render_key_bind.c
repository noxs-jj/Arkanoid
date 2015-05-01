#include "../../includes/projet.h"

int	key_hook(int keycode, t_data *d)
{
	(void)d;
	w_log("Enter to key_hook");
	if (65307 == keycode || 113 == keycode) // ECHAP Q
	{
		w_log("Press ECHAP >> Exit Success !!!");
		exit(0);
	}
	else
	{	
		w_log("key bind ELSE, relunch run_fractol");
		w_log(ft_itoa(keycode));
	}
	return (0);
}
