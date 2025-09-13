# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 20:22:45 by ynieto-s          #+#    #+#              #
#    Updated: 2025/09/13 17:14:49 by ynieto-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -Iinclude

MLX_DIR = MLX42
MLX_INCLUDE = $(MLX_DIR)/include
MLX_LIB = $(MLX_DIR)/build
MLX_LIBFILE = $(MLX_LIB)/libmlx42.a

MLX_FLAGS = -I $(MLX_INCLUDE) -L$(MLX_LIB) -lmlx42 -ldl -lglfw -pthread -lm

SRC =	src/so_long.c \
		src/close.c \
		src/error_exit.c \
		src/events.c \
		src/game.c \
		src/moves.c \
		src/render.c \
		src/valid_map.c \
		src/validate_map.c \
		
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX_LIBFILE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	make -C libft

$(MLX_LIBFILE):
	cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	cmake --build $(MLX_DIR)/build
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY : all, clean, fclean, re
