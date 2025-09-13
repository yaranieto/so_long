# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 20:22:45 by ynieto-s          #+#    #+#              #
#    Updated: 2025/09/13 23:23:52 by ynieto-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include

MLX_DIR = MLX42
MLX_INCLUDE = $(MLX_DIR)/include
MLX_LIB = $(MLX_DIR)/build
MLX_LIBFILE = $(MLX_LIB)/libmlx42.a

MLX_FLAGS = -ldl -lglfw -pthread -lm

SRC = src/so_long.c \
	src/close.c \
	src/error_exit.c \
	src/events.c \
	src/game.c \
	src/moves.c \
	src/render.c \
	src/validate_map.c \
	src/valid_map.c \
	src/validate_map_extras.c \
	src/validate_map_utils.c \
	src/game_utils.c \
	src/map_reader.c \
	src/hooks.c \
	src/images.c \
	src/images_extra.c \
	src/error_exit_extra.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: lib_mlx lib_ft $(NAME)

lib_mlx:
	cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	cmake --build $(MLX_DIR)/build -j4

lib_ft:
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX_LIBFILE) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re lib_mlx lib_ft
