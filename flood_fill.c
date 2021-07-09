#include "cub3d.h"

void	flood_fill(t_data tmp, int x, int y, char new_char)
{
	if (x < 0 || y < 0 || x > tmp.x_max || y >= tmp.y_max ||
		tmp.map[y][x] == '\0')
	{
		error(4, &tmp);
	}
	if (tmp.map[y][x] != new_char && tmp.map[y][x] != '1' &&
		tmp.map[y][x] != '\0')
	{
		tmp.map[y][x] = new_char;
		flood_fill(tmp, x + 1, y, new_char);
		flood_fill(tmp, x - 1, y, new_char);
		flood_fill(tmp, x, y + 1, new_char);
		flood_fill(tmp, x, y - 1, new_char);
	}
}
