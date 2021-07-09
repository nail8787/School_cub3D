#include "cub3d.h"

int		color_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		close_win(void)
{
	exit(0);
	return (0);
}

void	handle_spaces(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' ')
			{
				data->map[y][x] = '1';
				x++;
			}
			else
				x++;
		}
		y++;
	}
}

void	find_max_x_y(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->data.x_max = 0;
	img->data.y_max = 0;
	while (img->data.map[y])
	{
		x = 0;
		while (img->data.map[y][x])
		{
			x++;
		}
		if (img->data.x_max < x)
			img->data.x_max = x;
		y++;
		if (img->data.y_max < y)
			img->data.y_max = y;
	}
}
