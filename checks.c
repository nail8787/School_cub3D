#include "cub3d.h"

void	check_save(t_data *data, char *src)
{
	if (ft_strncmp("--save", src, 7) != 0)
	{
		ft_putstr_fd("Error\nWrong second argument\n", 2);
		exit(0);
	}
	else
		data->save = 1;
}

void	check_cubend(char *src)
{
	while (*src != '.' && *src)
		src++;
	src++;
	if (*src != 'c' || *(src + 1) != 'u' || *(src + 2) != 'b')
	{
		ft_putstr_fd("Error\nWrong file extension on scene file\n", 2);
		exit(0);
	}
}

void	check_iden(t_data *data)
{
	if (!data->nth_text || !data->sth_text || !data->west_text ||
			!data->east_text || !data->sprt_text)
		data->error = 2;
	if (!data->map)
		data->error = 4;
	if (data->count_iden != 8)
		data->error = 5;
	if (data->error == 0)
		handle_spaces(data);
}
