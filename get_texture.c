#include "cub3d.h"

static void	get_addr(t_img *img)
{
	img->text_no.addr = (int *)mlx_get_data_addr(img->text_no.text,
		&img->text_no.bits_per_pixel, &img->text_no.line_length,
			&img->text_no.endian);
	img->text_so.addr = (int *)mlx_get_data_addr(img->text_so.text,
		&img->text_so.bits_per_pixel, &img->text_so.line_length,
			&img->text_so.endian);
	img->text_we.addr = (int *)mlx_get_data_addr(img->text_we.text,
		&img->text_we.bits_per_pixel, &img->text_we.line_length,
			&img->text_we.endian);
	img->text_ea.addr = (int *)mlx_get_data_addr(img->text_ea.text,
		&img->text_ea.bits_per_pixel, &img->text_ea.line_length,
			&img->text_ea.endian);
	img->text_spr.addr = (int *)mlx_get_data_addr(img->text_spr.text,
		&img->text_spr.bits_per_pixel, &img->text_spr.line_length,
			&img->text_spr.endian);
}

void		get_texture(t_img *img)
{
	img->text_no.text = mlx_xpm_file_to_image(img->mlx, img->data.nth_text,
		&img->text_no.width, &img->text_no.height);
	img->text_so.text = mlx_xpm_file_to_image(img->mlx, img->data.sth_text,
		&img->text_so.width, &img->text_so.height);
	img->text_we.text = mlx_xpm_file_to_image(img->mlx, img->data.west_text,
		&img->text_we.width, &img->text_we.height);
	img->text_ea.text = mlx_xpm_file_to_image(img->mlx, img->data.east_text,
		&img->text_ea.width, &img->text_ea.height);
	img->text_spr.text = mlx_xpm_file_to_image(img->mlx, img->data.sprt_text,
		&img->text_spr.width, &img->text_spr.height);
	if (img->text_no.text != NULL && img->text_so.text != NULL &&
			img->text_we.text != NULL && img->text_ea.text != NULL &&
				img->text_spr.text != NULL)
		get_addr(img);
	else
		img->data.error = 2;
}
