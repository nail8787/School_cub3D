.PHONY = all re clean fclean

NAME = cub3D

SRC = cub3d.c get_next_line.c map.c pars_checkers.c parser_iden.c parser.c \
		cub_utils.c game3d.c my_mlx_pixel_put.c get_texture.c find_player.c \
		util_func.c add_sprt.c find_sprt.c new_sprt.c sort_sprt.c screenshot.c \
		draw_sprite.c key_press.c draw_screen.c texture_color.c checks.c \
		errors.c valid_map.c flood_fill.c
OBJ = $(SRC:.c=.o)
HEADER = cub3d.h
LIBFTDIR = ./libft/
MLXDIR = ./mlx/
LIBFT = $(LIBFTDIR)libft.a
MLX = $(MLXDIR)libmlx.dylib
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft $(OBJ) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR) 
	cp $(MLXDIR)libmlx.dylib ./

%.o:%.c $(HEADER)
		gcc $(CFLAGS) -I ./mlx.h -c $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	/bin/rm -f libmlx.dylib
	/bin/rm -f $(MLXDIR)ibmlx.dylib
	/bin/rm -f $(NAME)

re: fclean all
