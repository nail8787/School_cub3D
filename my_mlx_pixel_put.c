#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		pix_color(t_img *img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}
