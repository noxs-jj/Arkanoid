#include "../../includes/projet.h"

int	mlx_pointer_hook(t_win_list *win_ptr, int (*funct_ptr)(), void *param)
{
	win_ptr->hooks[MotionNotify].hook = funct_ptr;
	win_ptr->hooks[MotionNotify].param = param;
	win_ptr->hooks[MotionNotify].mask = PointerMotionMask;
	return (0);
}
