SRCS = get_next_line_utils.c \
get_next_line.c \
main.c \
init.c \
data_init.c \
forMap.c \
takeMap.c \
utils.c \
init_utils.c\
raycast.c\
render.c \
keys.c \
text.c \
let_free.c \
error.c \
keys2.c \
utils2.c \
utils3.c \
raycast2.c


CC = gcc

MLX = mlx/libmlx.a

LIBFT = libft-main/libft.a

CFLAGS = -Wall -Wextra -Werror -g

NAME = cub3D

FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

all: $(NAME)

OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(FRAMEWORK) $(LIBFT) -o $(NAME)

$(MLX):
	make -C mlx

$(LIBFT):
	make -C libft-main

clean:
	make clean -C mlx
	make clean -C libft-main
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft-main

re: fclean all

.PHONY: fclean clean re
