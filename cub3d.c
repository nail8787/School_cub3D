#include "cub3d.h"

static void	init_data(t_data *data)
{
	data->res_x = 0;
	data->res_y = 0;
	data->nth_text = NULL;
	data->sth_text = NULL;
	data->west_text = NULL;
	data->east_text = NULL;
	data->sprt_text = NULL;
	data->floor_r = -1;
	data->floor_g = -1;
	data->floor_b = -1;
	data->ceil_r = -1;
	data->ceil_g = -1;
	data->ceil_b = -1;
	data->error = 0;
	data->save = 0;
	data->count_iden = 0;
	data->map_str = NULL;
	data->map = NULL;
}

int			main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc == 2 || argc == 3)
	{
		init_data(&data);
		if (argc == 3)
			check_save(&data, argv[2]);
		check_cubend(argv[1]);
		fd = 0;
		pars_file(argv[1], &data, fd);
		game(&data);
	}
	else
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
	return (0);
}
