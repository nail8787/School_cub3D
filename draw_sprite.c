#include "cub3d.h"

static int	color_sprt(t_img *img, int x, int y, double sprt_size)
{
	double	scale;
	int		color;

	scale = 64.0 / sprt_size;
	color = img->text_spr.addr[(int)(y * scale) * img->text_spr.width +
		(int)(x * scale) % img->text_spr.height];
	return (color);
}

static void	draw_cycle_y(t_img *img, t_sprt_calc sp_c, int x)
{
	int y;
	int color;

	y = 0;
	while (y < sp_c.sp_size)
	{
		color = color_sprt(img, x, y, sp_c.sp_size);
		if ((sp_c.sp_y + y) < 0 || (sp_c.sp_y + y) >= img->data.res_y)
			y++;
		else if (color == 0)
			y++;
		else
		{
			my_mlx_pixel_put(img, sp_c.sp_x + x, sp_c.sp_y + y, color);
			y++;
		}
	}
}

static void	draw_cycle_sp(t_img *img, t_sprt_calc sp_c, t_sprt *tmp,
	double *buf)
{
	int x;

	x = 0;
	while (x < sp_c.sp_size)
	{
		if ((sp_c.sp_x + x) < 0 || (sp_c.sp_x + x) >= img->data.res_x)
			x++;
		else if (buf[(int)sp_c.sp_x + x] < tmp->len)
			x++;
		else
		{
			draw_cycle_y(img, sp_c, x);
			x++;
		}
	}
}

void		draw_sprt(t_img *img, t_sprt *tmp, double *buf)
{
	t_sprt_calc sp_c;

	sp_c.sp_dir = atan2(tmp->sy - img->plr.py, tmp->sx - img->plr.px);
	while (sp_c.sp_dir - img->plr.pa > M_PI)
		sp_c.sp_dir -= 2 * M_PI;
	while (sp_c.sp_dir - img->plr.pa < -M_PI)
		sp_c.sp_dir += 2 * M_PI;
	sp_c.sp_size = img->data.res_y / tmp->len;
	sp_c.sp_x = (sp_c.sp_dir - img->plr.pa) / (M_PI / 6) * (img->data.res_x / 2)
		+ (img->data.res_x / 2) - sp_c.sp_size / 2;
	sp_c.sp_y = img->data.res_y / 2 - sp_c.sp_size / 2;
	draw_cycle_sp(img, sp_c, tmp, buf);
}

void		next_sprt(t_img *img, double *buf)
{
	t_sprt *head;

	head = img->sprt;
	while (head != NULL)
	{
		draw_sprt(img, head, buf);
		head = head->next;
	}
}
