#include "cub3d.h"

void	read_map(char *line, t_data *data)
{
	char *tmp;

	if (*line == '\0' && data->map_str == NULL)
		return (my_free(&line));
	else if (*line == '\0' && data->map_str != NULL)
	{
		data->error = 4;
		return ;
	}
	tmp = line;
	line = ft_strjoin(line, "!");
	my_free(&tmp);
	if (data->map_str == NULL)
	{
		data->map_str = ft_strdup(line);
		my_free(&line);
	}
	else
	{
		tmp = data->map_str;
		data->map_str = ft_strjoin(data->map_str, line);
		my_free(&tmp);
		my_free(&line);
	}
}
