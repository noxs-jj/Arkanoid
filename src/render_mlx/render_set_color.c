#include "../../includes/projet.h"

void	render_set_color(int red, int green, int blue)
{
	static t_data	*d = NULL;

	if (NULL == d)
		d = getData();
	d->color->red = red;
	d->color->green = green;
	d->color->blue = blue;
}
