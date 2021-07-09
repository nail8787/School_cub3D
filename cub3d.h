#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 32
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_data {
	int				res_x;
	int				res_y;
	char			*nth_text;
	char			*sth_text;
	char			*west_text;
	char			*east_text;
	char			*sprt_text;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceil_r;
	int				ceil_g;
	int				ceil_b;
	int				error;
	int				x_max;
	int				y_max;
	int				count_iden;
	char			*map_str;
	char			**map;
	int				save;
}					t_data;

typedef struct		s_plr {
	double			px;
	double			py;
	double			pa;
	double			start;
	double			end;
}					t_plr;

typedef struct		s_texture {
	void			*text;
	int				*addr;
	int				height;
	int				width;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			scale;
}					t_texture;

typedef struct		s_r_cast {
	double			disttowall;
	int				ceil_h;
	int				flr_h;
	int				colm_h;
	int				side;
	double			step_x;
	double			step_y;
	double			scale;
}					t_r_cast;

typedef struct		s_sprt {
	double			sx;
	double			sy;
	double			len;
	struct s_sprt	*next;
}					t_sprt;

typedef struct		s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
	t_data			data;
	t_plr			plr;
	t_r_cast		r_cast;
	t_texture		text_no;
	t_texture		text_so;
	t_texture		text_we;
	t_texture		text_ea;
	t_texture		text_spr;
	t_sprt			*sprt;
}					t_img;

typedef struct		s_sprt_calc {
	double			sp_dir;
	double			sp_size;
	double			sp_x;
	double			sp_y;
}					t_sprt_calc;

int					get_next_line(int fd, char **line);
void				pars_file(char *file, t_data *data, int fd);
void				iden_r(char *line, t_data *data);
void				iden_text(char *line, t_data *data, char iden);
void				iden_f(char *line, t_data *data);
void				iden_c(char *line, t_data *data);
void				del_text_spaces(t_data *data);
int					check_all_iden(t_data *data);
void				my_free(char **smth);
void				read_map(char *line, t_data *data);
void				game(t_data *data);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				get_texture(t_img *img);
int					texture_color(t_img *img, t_r_cast r_cast,
						t_plr plr, int pos);
int					color_rgb(int t, int r, int g, int b);
int					close_win(void);
int					key_press(int keycode, t_img *img);
void				find_sprt(t_img *img);
void				add_sprt_back(t_img *img, t_sprt *new);
void				sort_sprt(t_img *img);
void				find_len_sprt(t_img *img);
void				draw_sprt(t_img *img, t_sprt *tmp, double *buf);
void				next_sprt(t_img *img, double *buf);
void				screenshot(t_img *img);
int					pix_color(t_img *img, int x, int y);
void				draw_screen(t_img *img);
void				find_plr(t_img *img);
t_sprt				*new_sprt(double x, double y);
void				check_save(t_data *data, char *src);
void				check_cubend(char *src);
void				error_open(void);
void				error_malloc(char *tmp);
void				error(int num_err, t_data *data);
void				free_all(t_data *data);
void				check_iden(t_data *data);
void				handle_spaces(t_data *data);
void				valid_map(t_data *data);
void				flood_fill(t_data tmp, int x, int y, char new_char);
void				clear_map(t_data *tmp);
void				find_max_x_y(t_img *img);
#endif
