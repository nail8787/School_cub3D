#include "cub3d.h"

int	check_all_iden(t_data *data)
{
	if (data->res_x == 0 || data->res_y == 0)
		return (-1);
	if (data->nth_text == NULL || data->sth_text == NULL ||
			data->west_text == NULL || data->east_text == NULL ||
				data->sprt_text == NULL)
		return (-1);
	if (data->floor_r == -1 && data->floor_g == -1 && data->floor_b == -1)
		return (-1);
	if (data->ceil_r == -1 && data->ceil_g == -1 && data->ceil_b == -1)
		return (-1);
	else
		return (1);
}
