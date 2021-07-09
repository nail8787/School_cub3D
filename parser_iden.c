#include "cub3d.h"

void		iden_r(char *line, t_data *data)
{
	data->count_iden++;
	while (*line == ' ' && *line)
		line++;
	data->res_x = ft_atoi(line);
	while (*line >= '0' && *line <= '9' && *line)
		line++;
	while (*line == ' ' && *line)
		line++;
	data->res_y = ft_atoi(line);
	while (*line >= '0' && *line <= '9' && *line)
		line++;
	if (data->res_x <= 0 || data->res_y <= 0 || *line != '\0'
		|| data->res_x > 15000 || data->res_y > 15000)
		data->error = 1;
}

void		iden_text(char *line, t_data *data, char iden)
{
	data->count_iden++;
	while (*line != '.' && *line == ' ' && *line)
		line++;
	if (iden == 'N')
		data->nth_text = ft_strdup(line);
	if (iden == 'S')
		data->sth_text = ft_strdup(line);
	if (iden == 'W')
		data->west_text = ft_strdup(line);
	if (iden == 'E')
		data->east_text = ft_strdup(line);
	if (iden == 's')
		data->sprt_text = ft_strdup(line);
}

static char	*skip_check(char *line, t_data *data)
{
	while (*line >= '0' && *line <= '9' && *line)
		line++;
	while (*line == ' ' && *line)
		line++;
	if (*line != ',')
		data->error = 3;
	line++;
	while (*line == ' ' && *line)
		line++;
	if (*line < '0' || *line > '9')
		data->error = 3;
	return (line);
}

void		iden_f(char *line, t_data *data)
{
	data->count_iden++;
	while (*line == ' ' && *line)
		line++;
	if (*line < '0' || *line > '9')
		data->error = 3;
	data->floor_r = ft_atoi(line);
	line = skip_check(line, data);
	data->floor_g = ft_atoi(line);
	line = skip_check(line, data);
	data->floor_b = ft_atoi(line);
	while (*line >= '0' && *line <= '9' && *line)
		line++;
	if (data->floor_r < 0 || data->floor_r > 255 || data->floor_g < 0 ||
	data->floor_g > 255 || data->floor_b < 0 || data->floor_b > 255 ||
		*line != '\0')
		data->error = 3;
}

void		iden_c(char *line, t_data *data)
{
	data->count_iden++;
	while (*line == ' ' && *line)
		line++;
	if (*line < '0' || *line > '9')
		data->error = 3;
	data->ceil_r = ft_atoi(line);
	line = skip_check(line, data);
	data->ceil_g = ft_atoi(line);
	line = skip_check(line, data);
	data->ceil_b = ft_atoi(line);
	while (*line >= '0' && *line <= '9' && *line)
		line++;
	if (data->ceil_r < 0 || data->ceil_r > 255 || data->ceil_g < 0 ||
	data->ceil_g > 255 || data->ceil_b < 0 || data->ceil_b > 255 ||
		*line != '\0')
		data->error = 3;
}
