#include "cub3d.h"

static void	bmp_content(t_img *img, int fd)
{
	int	x;
	int	y;
	int	color;

	y = img->data.res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < img->data.res_x)
		{
			color = pix_color(img, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
	}
}

static void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)n;
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void	bmp_header(t_img *img, int fd)
{
	unsigned char	header[54];
	int				i;
	int				filesize;

	i = 0;
	filesize = (img->data.res_x * img->data.res_y) * 4 + 54;
	while (i < 54)
		header[i++] = 0;
	header[0] = 'B';
	header[1] = 'M';
	int_to_char(filesize, &header[2]);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	int_to_char(img->data.res_x, &header[18]);
	int_to_char(img->data.res_y, &header[22]);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(fd, header, 54);
}

static int	make_screenshot(t_img *img)
{
	int	fd;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC |
		O_APPEND, 0666)) < 0)
		return (0);
	bmp_header(img, fd);
	bmp_content(img, fd);
	close(fd);
	return (1);
}

void		screenshot(t_img *img)
{
	if (img->data.save == 1)
	{
		if (make_screenshot(img) == 0)
			ft_putstr_fd("Error\nFail in making screenshot", 2);
		exit(0);
	}
}
