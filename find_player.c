#include "cub3d.h"

static void	plr_pos(t_img *img, int x, int y)
{
	img->plr.px = x + 0.5;
	img->plr.py = y + 0.5;
	if (img->data.map[y][x] == 'N')
		img->plr.pa = 3 * M_PI_2;
	if (img->data.map[y][x] == 'S')
		img->plr.pa = M_PI_2;
	if (img->data.map[y][x] == 'W')
		img->plr.pa = M_PI;
	if (img->data.map[y][x] == 'E')
		img->plr.pa = 0;
	img->data.map[y][x] = '0';
}

void		find_plr(t_img *img)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (img->data.map[y])
	{
		while (img->data.map[y][x])
		{
			if (img->data.map[y][x] == 'N' || img->data.map[y][x] == 'S' ||
				img->data.map[y][x] == 'E' || img->data.map[y][x] == 'W')
			{
				plr_pos(img, x, y);
				x++;
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
}
