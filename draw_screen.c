#include "cub3d.h"

static void	draw_side(t_img *img, t_r_cast *r_cast, t_plr plr)
{
	if (r_cast->side == 0)
	{
		if (plr.px > img->plr.px)
			r_cast->side = 0;
		else
			r_cast->side = 1;
	}
	else if (r_cast->side == 1)
	{
		if (plr.py > img->plr.py)
			r_cast->side = 2;
		else
			r_cast->side = 3;
	}
}

static void	draw_y(t_img *img, t_r_cast r_cast, t_plr plr, int x)
{
	int y;

	y = 0;
	while (y < img->data.res_y)
	{
		if (y <= r_cast.ceil_h)
			my_mlx_pixel_put(img, x, y, color_rgb(0, img->data.ceil_r,
				img->data.ceil_g, img->data.ceil_b));
		else if (y > r_cast.ceil_h && y <= r_cast.flr_h)
			my_mlx_pixel_put(img, x, y,
				texture_color(img, r_cast, plr, y - (r_cast.ceil_h + 1)));
		else
			my_mlx_pixel_put(img, x, y, color_rgb(0, img->data.floor_r,
				img->data.floor_g, img->data.floor_b));
		y++;
	}
}

static void	casting(t_img *img, t_plr *plr, t_r_cast *r_cast)
{
	while (img->data.map[(int)plr->py][(int)plr->px] != '1' &&
		img->data.map[(int)plr->py][(int)plr->px])
	{
		r_cast->disttowall += 0.00001;
		plr->px += cos(plr->start) * r_cast->disttowall;
		if (img->data.map[(int)plr->py][(int)plr->px] == '1')
			r_cast->side = 0;
		else
			r_cast->side = 1;
		plr->py += sin(plr->start) * r_cast->disttowall;
		if (plr->py < 0)
			plr->py = 1;
		if (plr->py > img->data.y_max - 1)
			plr->py = img->data.y_max - 1;
		if (plr->px < 0)
			plr->px = 1;
		if (plr->px > img->data.x_max - 1)
			plr->px = img->data.x_max - 1;
	}
}

static void	raycast(t_img *img, t_plr plr, double *buf)
{
	int			x;
	t_r_cast	r_cast;

	x = 0;
	while (plr.start < plr.end && x < img->data.res_x)
	{
		r_cast.disttowall = 0;
		plr.py = img->plr.py;
		plr.px = img->plr.px;
		r_cast.step_x = 0;
		r_cast.step_y = 0;
		casting(img, &plr, &r_cast);
		r_cast.step_x = img->plr.px - plr.px;
		r_cast.step_y = img->plr.py - plr.py;
		r_cast.disttowall = sqrt(pow(r_cast.step_x, 2) + pow(r_cast.step_y, 2));
		buf[x] = r_cast.disttowall;
		r_cast.colm_h = (img->data.res_y) /
			(r_cast.disttowall * cos(plr.pa - plr.start));
		r_cast.ceil_h = img->data.res_y / 2 - r_cast.colm_h / 2;
		r_cast.flr_h = img->data.res_y - r_cast.ceil_h;
		draw_side(img, &r_cast, plr);
		draw_y(img, r_cast, plr, x);
		x++;
		plr.start += (M_PI / 3) / (img->data.res_x);
	}
}

void		draw_screen(t_img *img)
{
	t_plr	plr;
	double	buf[img->data.res_x];

	plr = img->plr;
	plr.start = plr.pa - M_PI / 6;
	plr.end = plr.pa + M_PI / 6;
	raycast(img, plr, buf);
	if (img->sprt != NULL)
	{
		find_len_sprt(img);
		sort_sprt(img);
		next_sprt(img, buf);
	}
	screenshot(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
}
