#include "cub3d.h"

static int	west_color(t_img *img, t_plr plr, t_r_cast r_cast, int pos)
{
	int tex_x;
	int tex_y;
	int color;

	tex_x = img->text_we.width - (plr.py * (double)img->text_we.width);
	tex_y = (int)(pos * r_cast.scale) & (img->text_we.height - 1);
	color = img->text_we.addr[tex_y * img->text_we.height + tex_x];
	return (color);
}

static int	east_color(t_img *img, t_plr plr, t_r_cast r_cast, int pos)
{
	int tex_x;
	int tex_y;
	int color;

	tex_x = img->text_ea.width - (plr.py * (double)img->text_ea.width);
	tex_y = (int)(pos * r_cast.scale) & (img->text_ea.height - 1);
	color = img->text_ea.addr[tex_y * img->text_ea.height + tex_x];
	return (color);
}

static int	nrth_color(t_img *img, t_plr plr, t_r_cast r_cast, int pos)
{
	int tex_x;
	int tex_y;
	int color;

	tex_x = img->text_no.width - (plr.px * (double)img->text_no.width);
	tex_y = (int)(pos * r_cast.scale) & (img->text_no.height - 1);
	color = img->text_no.addr[tex_y * img->text_no.height + tex_x];
	return (color);
}

static int	sth_color(t_img *img, t_plr plr, t_r_cast r_cast, int pos)
{
	int tex_x;
	int tex_y;
	int color;

	tex_x = img->text_so.width - (plr.px * (double)img->text_so.width);
	tex_y = (int)(pos * r_cast.scale) & (img->text_so.height - 1);
	color = img->text_so.addr[tex_y * img->text_so.height + tex_x];
	return (color);
}

int			texture_color(t_img *img, t_r_cast r_cast, t_plr plr, int pos)
{
	int color;

	plr.py -= floor(plr.py);
	plr.px -= floor(plr.px);
	r_cast.scale = 64.0 / r_cast.colm_h;
	if (r_cast.side == 0)
		color = west_color(img, plr, r_cast, pos);
	else if (r_cast.side == 1)
		color = east_color(img, plr, r_cast, pos);
	else if (r_cast.side == 2)
		color = nrth_color(img, plr, r_cast, pos);
	else
		color = sth_color(img, plr, r_cast, pos);
	return (color);
}
