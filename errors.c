#include "cub3d.h"

void		error_open(void)
{
	ft_putstr_fd("Error\nWhile opening file\n", 2);
	exit(0);
}

void		error_malloc(char *tmp)
{
	my_free(&tmp);
	ft_putstr_fd("Error\nMalloc error\n", 2);
	exit(0);
}

static void	error_4(t_data *data)
{
	int	i;

	i = 0;
	free_all(data);
	if (data->map)
	{
		while (data->map[i])
			my_free(&data->map[i++]);
		my_free(data->map);
	}
	ft_putstr_fd("Error\nInvalid map\n", 2);
}

void		error(int num_err, t_data *data)
{
	int	i;

	i = 0;
	if (num_err == 1)
		ft_putstr_fd("Error\nInvalid resolution\n", 2);
	if (num_err == 2)
	{
		free_all(data);
		ft_putstr_fd("Error\nInvalid texture\n", 2);
	}
	if (num_err == 3)
	{
		free_all(data);
		ft_putstr_fd("Error\nInvalid color of ceiling or floor\n", 2);
	}
	if (num_err == 4)
		error_4(data);
	if (num_err == 5)
	{
		free_all(data);
		ft_putstr_fd("Error\nInvalid identificator\n", 2);
	}
	exit(0);
}
