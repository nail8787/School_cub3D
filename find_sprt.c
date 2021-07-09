#include "cub3d.h"

void	find_sprt(t_img *img)
{
	int		x;
	int		y;

	y = 0;
	while (img->data.map[y])
	{
		x = 0;
		while (img->data.map[y][x])
		{
			if (img->data.map[y][x] == '2')
			{
				add_sprt_back(img, new_sprt(x + 0.499, y + 0.499));
				x++;
			}
			else
				x++;
		}
		y++;
	}
}
