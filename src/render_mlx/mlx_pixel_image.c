#include "../../includes/projet.h"

int	mlx_pixel_image(int x, int y, t_data *d)
{
	int	pix;

	pix = (x * d->bit_pixel / 8) + (y * d->line_size);
	if (0 == d->bit_pixel || 0 == d->line_size)
		return (error("Bits per pixel || Line_size: wrongs size"));
	d->img_data[pix] = d->color->blue;
	d->img_data[pix + 1] = d->color->green;
	d->img_data[pix + 2] = d->color->red;
	d->img_data[pix + 3] = 0;
	return (0);
}
