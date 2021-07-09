#include "cub3d.h"
#include <stdio.h>

static void	check_screen_size(t_img *img)
{
	int res_x;
	int res_y;

	mlx_get_screen_size(img->mlx, &res_x, &res_y);
	if (img->data.res_x > res_x || img->data.res_y > res_y)
	{
		if (img->data.res_x > res_x)
			img->data.res_x = res_x;
		if (img->data.res_y > res_y)
			img->data.res_y = res_y;
	}
}

void		game(t_data *data)
{
	t_img	img;

	img.data = *data;
	img.mlx = mlx_init();
	check_screen_size(&img);
	get_texture(&img);
	if (img.data.error != 0)
		error(img.data.error, &img.data);
	img.mlx_win = mlx_new_window(img.mlx, img.data.res_x,
		img.data.res_y, "Cub3D");
	img.img = mlx_new_image(img.mlx, img.data.res_x, img.data.res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	img.sprt = NULL;
	find_plr(&img);
	find_sprt(&img);
	find_max_x_y(&img);
	flood_fill(img.data, img.plr.px - 0.5, img.plr.py - 0.5, '5');
	draw_screen(&img);
	mlx_hook(img.mlx_win, 2, 1L << 0, &key_press, &img);
	mlx_hook(img.mlx_win, 17, 1L << 17, &close_win, &img);
	mlx_loop(img.mlx);
}
