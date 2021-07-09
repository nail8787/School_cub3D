#include "cub3d.h"

static void		up(t_img *img)
{
	img->plr.py += sin(img->plr.pa) / 2;
	img->plr.px += cos(img->plr.pa) / 2;
	if ((img->data.map[(int)img->plr.py][(int)img->plr.px] == '1') ||
		!(img->data.map[(int)img->plr.py][(int)img->plr.px]) ||
		img->plr.px <= 1 || img->plr.py <= 1 || img->plr.px >
		(img->data.x_max - 1) || img->plr.py > (img->data.y_max - 1))
	{
		img->plr.py -= sin(img->plr.pa) / 2;
		img->plr.px -= cos(img->plr.pa) / 2;
	}
}

static void		down(t_img *img)
{
	img->plr.py -= sin(img->plr.pa) / 2;
	img->plr.px -= cos(img->plr.pa) / 2;
	if ((img->data.map[(int)img->plr.py][(int)img->plr.px] == '1') ||
		!(img->data.map[(int)img->plr.py][(int)img->plr.px]) ||
		img->plr.px <= 1 || img->plr.py <= 1 || img->plr.px >
		(img->data.x_max - 1) || img->plr.py > (img->data.y_max - 1))
	{
		img->plr.py += sin(img->plr.pa) / 2;
		img->plr.px += cos(img->plr.pa) / 2;
	}
}

static void		left(t_img *img)
{
	img->plr.py -= cos(img->plr.pa) / 2;
	img->plr.px += sin(img->plr.pa) / 2;
	if ((img->data.map[(int)img->plr.py][(int)img->plr.px] == '1') ||
		!(img->data.map[(int)img->plr.py][(int)img->plr.px]) ||
		img->plr.px <= 1 || img->plr.py <= 1 || img->plr.px >
		(img->data.x_max - 1) || img->plr.py > (img->data.y_max - 1))
	{
		img->plr.py += cos(img->plr.pa) / 2;
		img->plr.px -= sin(img->plr.pa) / 2;
	}
}

static void		right(t_img *img)
{
	img->plr.py += cos(img->plr.pa) / 2;
	img->plr.px -= sin(img->plr.pa) / 2;
	if ((img->data.map[(int)img->plr.py][(int)img->plr.px] == '1') ||
		!(img->data.map[(int)img->plr.py][(int)img->plr.px]) ||
		img->plr.px <= 1 || img->plr.py <= 1 || img->plr.px >
		(img->data.x_max - 1) || img->plr.py > (img->data.y_max - 1))
	{
		img->plr.py -= cos(img->plr.pa) / 2;
		img->plr.px += sin(img->plr.pa) / 2;
	}
}

int				key_press(int keycode, t_img *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 13)
		up(img);
	if (keycode == 1)
		down(img);
	if (keycode == 0)
		left(img);
	if (keycode == 2)
		right(img);
	if (keycode == 123)
		img->plr.pa -= 0.15;
	if (keycode == 124)
		img->plr.pa += 0.15;
	if (keycode == 53)
		exit(0);
	draw_screen(img);
	return (0);
}
