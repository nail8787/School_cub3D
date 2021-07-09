#include "cub3d.h"

static void	check_char(t_data *data, int count)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != 'N' && data->map[y][x] != 'S' &&
					data->map[y][x] != 'E' && data->map[y][x] != 'W' &&
						data->map[y][x] != '0' && data->map[y][x] != '1' &&
							data->map[y][x] != '2')
			{
				count++;
				x++;
			}
			else
				x++;
		}
		y++;
	}
	if (count > 0)
		data->error = 4;
}

static void	check_player(t_data *data)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||
				data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				count++;
				x++;
			}
			else
				x++;
		}
		y++;
	}
	if (count != 1)
		data->error = 4;
}

void		valid_map(t_data *data)
{
	int	count;

	count = 0;
	if (data->error == 0)
	{
		check_player(data);
		check_char(data, count);
	}
}
