/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:49 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:14:01 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_window(t_game *game)
{
	int32_t	width;
	int32_t	height;

	width = game->map.width * game->map.tile_size;
	height = game->map.height * game->map.tile_size;
	game->mlx = mlx_init(width, height, "so_long", true);
	if (!game->mlx)
		error_exit("Error initializing MLX");
	
	load_images(game);
	render_map(game);
	
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop_hook(game->mlx, &hook, game);
	mlx_loop(game->mlx);
}

void	init_game(t_game *game)
{
	game->steps = 0;
	game->map.total_collectibles = 0;
	game->map.num_collectibles = 0;
	game->map.tile_size = 64;
	game->map.offset_x = 0;
	game->map.offset_y = 0;
	player_position(&game->map, game);
}

void	start_game(t_game *game)
{
	init_game(game);
	setup_window(game);
}

static void	handle_collectible(t_game *game, int nx, int ny)
{
	game->map.map[ny][nx] = '0';
	game->map.num_collectibles++;
	size_t idx = 0;
	while (idx < game->collectible.img->count)
	{
		if (game->collectible.img->instances[idx].x == nx * game->map.tile_size &&
			game->collectible.img->instances[idx].y == ny * game->map.tile_size)
		{
			game->collectible.img->instances[idx].enabled = false;
			break;
		}
		idx++;
	}
}

static void	handle_player_move(t_game *game, int nx, int ny)
{
	game->map.map[game->player_y][game->player_x] = '0';
	game->map.map[ny][nx] = 'P';
	game->player.img->instances[0].x = nx * game->map.tile_size;
	game->player.img->instances[0].y = ny * game->map.tile_size;
	game->player_x = nx;
	game->player_y = ny;
	game->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putstr_fd("\n", 1);
}

int	move_player(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	next_tile;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	next_tile = game->map.map[ny][nx];
	if (next_tile == '1')
		return (0);
	if (next_tile == 'E' && game->map.num_collectibles != game->map.total_collectibles)
		return (0);
	if (next_tile == 'C')
		handle_collectible(game, nx, ny);
	if (next_tile == 'E' && game->map.num_collectibles == game->map.total_collectibles)
	{
		ft_putstr_fd("You win!\n", 1);
		close_window(game);
		return (1);
	}
	handle_player_move(game, nx, ny);
	return (1);
}

void	player_position(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->map.total_collectibles = check_the_element(map->map, 'C');
				game->map.num_collectibles = 0;
				game->steps = 0;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: player not found in map");
}
