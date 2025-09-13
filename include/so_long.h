/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:07:13 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 23:21:01 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		total_collectibles;
	int		num_collectibles;
	int		tile_size;
	int		offset_x;
	int		offset_y;
}	t_map;

typedef struct s_img_instance
{
	mlx_image_t	*img;
	int32_t		instance_id;
}	t_img_instance;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			map;
	t_img_instance	player;
	t_img_instance	wall;
	t_img_instance	collectible;
	t_img_instance	exit;
	t_img_instance	floor;
	int				player_x;
	int				player_y;
	int				steps;
}	t_game;

// Core game functions
void	start_game(t_game *game);
void	setup_window(t_game *game);
void	init_game(t_game *game);
void	load_images(t_game *game);
void	load_images_extra(t_game *game);
void	render_map(t_game *game);

// Image loading functions
void	load_exit_image(t_game *game);
void	load_wall_image(t_game *game);
void	load_collectible_image(t_game *game);
void	load_floor_image(t_game *game);
void	copy_texture_to_image(mlx_image_t *img, mlx_texture_t *tex);

// Movement functions
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		move_player(t_game *game, int dx, int dy);
void	handle_player_move(t_game *game, int nx, int ny);

// Map functions
char	**read_map(const char *filename);
void	build_map(int fd, char **map, int lines);
int		count_lines_file(const char *filename);
char	*read_line(int fd);
char	*add_char(char *line, char c, int *len);

// Map validation functions
void	validate_map(t_map *map);
int		valid_map(t_map *map);
void	check_extension(char *filename);
int		check_the_element(char **map, char element);
int		check_rectangular(t_map *map);
int		check_walls(t_map *map);
int		check_chars(t_map *map);
int		check_all_elements(t_map *map);
int		check_ber_extension(char *str1, char *str2, size_t n);
int		validate_map_chars(t_map *map);
int		validate_map_borders(t_map *map);
int		count_map_elements(t_map *map, char element);
void	check_map_elements(t_map *map);
int		validate_game(t_game *game);
void	flood_fill(char **map, t_map map_info, int y, int x);
int		check_access(char **map, int height, int width);

// Event functions
void	key_hook(mlx_key_data_t keydata, void *param);
void	hook(void *param);
void	close_window(void *param);
int		close_game(t_game *game);

// Utils
void	error_exit(const char *message);
void	print_error(const char *message);
int		count_lines(char **map);
void	ft_memdel(void *ptr);
void	free_map(char **array);
void	player_position(t_map *map, t_game *game);

#endif
