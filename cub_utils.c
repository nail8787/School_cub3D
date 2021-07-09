#include "cub3d.h"

void	my_free(char **smth)
{
	if (*smth)
	{
		free(*smth);
		*smth = NULL;
	}
}

void	free_all(t_data *data)
{
	my_free(&data->nth_text);
	my_free(&data->sth_text);
	my_free(&data->west_text);
	my_free(&data->east_text);
	my_free(&data->sprt_text);
	my_free(&data->map_str);
}
