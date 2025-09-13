/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:07:13 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 18:34:06 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

// Estructura del mapa.
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		num_collectibles;
	int		exit;
	int		total_collectibles;
	int		player;
	
}	t_map;

//Estructura sobre el juego y el jugador.
typedef struct s_game
{
	mlx_t		*mlx;
	void		*window;
	t_map		map;
	int			player_x;
	int			player_y;
	int			moves;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collectible;
	int			img_width;
	int			img_height;
	int			steps;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

char	**read_map(const char *filename);
void	build_map(int fd, char **map, int lines);
int		count_lines_file(const char *filename);
char	*read_line(int fd);
char	*add_char(char *line, char c, int *len);
int		check_rectangular(char **map);
int		check_walls(char **map);
int		check_chars(char **map);
int 	check_all_elements(char **map);
int		check_the_element(char **map, char c);
int		valid_map(char **map);
int		validate_game(t_game *game);
int		check_access(char ** map, int height, int width);
void	flood_fill(char **map, t_map map_info, int y, int x);
void	ft_memdel(void *ptr);
void	free_map(char **array);
void	exit_free_error(const char *msg, t_game *game);
int		count_lines(char **map);
int		check_ber_extension(char *str1, char *str2, size_t n);
char	*get_next_line(int fd);
void	error_exit(const char *msg);
void	start_game(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
void	key_hook(mlx_key_data_t keydata, void *param);
void	close_window(void *param);
int		close_game(t_game *game);
int		move_player(t_game *game, int dx, int dy);
int		player_steps(t_game *game, int nx, int ny);
void	move_up(t_game *game);
void 	move_left(t_game *game);
void 	move_down(t_game *game);
void 	move_right(t_game *game);
void	player_position(t_map *map, t_game *game);
