#include "cub3d.h"

static void	check_none(char *line, t_data *data)
{
	if (*line != 'R' && (*line != 'N' && *(line + 1) != 'O') &&
		(*line != 'S' && *(line + 1) != 'O') &&
			(*line != 'W' && *(line + 1) != 'E') &&
				(*line != 'E' && *(line + 1) != 'A') &&
					*line != 'F' && *line != 'C' &&
						(*line != 'S' && *(line + 1) != ' '))
		data->error = 5;
}

static void	check_line(char *line, t_data *data)
{
	char	*tmp;

	if (!line || *line == '\0')
		return (my_free(&line));
	tmp = line;
	line = ft_strtrim(line, " ");
	my_free(&tmp);
	if (*line == 'R')
		iden_r(line + 1, data);
	if (*line == 'N' && *(line + 1) == 'O')
		iden_text(line + 2, data, 'N');
	if (*line == 'S' && *(line + 1) == 'O')
		iden_text(line + 2, data, 'S');
	if (*line == 'W' && *(line + 1) == 'E')
		iden_text(line + 2, data, 'W');
	if (*line == 'E' && *(line + 1) == 'A')
		iden_text(line + 2, data, 'E');
	if (*line == 'S' && *(line + 1) == ' ')
		iden_text(line + 1, data, 's');
	if (*line == 'F')
		iden_f(line + 1, data);
	if (*line == 'C')
		iden_c(line + 1, data);
	check_none(line, data);
	free(line);
}

void		pars_file(char *file, t_data *data, int fd)
{
	char	*line;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		error_open();
	while (get_next_line(fd, &line))
	{
		if (check_all_iden(data) == 1)
			read_map(line, data);
		else
		{
			check_line(line, data);
			if (data->error != 0)
				error(data->error, data);
		}
	}
	read_map(line, data);
	data->map = ft_split(data->map_str, '!');
	my_free(&data->map_str);
	check_iden(data);
	valid_map(data);
	if (data->error != 0)
		error(data->error, data);
	close(fd);
}
