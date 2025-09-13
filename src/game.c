/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:49 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 23:21:42 by ynieto-s         ###   ########.fr       */
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
	size_t	idx;

	game->map.map[ny][nx] = '0';
	game->map.num_collectibles++;
	idx = 0;
	while (idx < game->collectible.img->count)
	{
		if (game->collectible.img->instances[idx].x == nx * game->map.tile_size
			&& game->collectible.img->instances[idx].y == ny
			* game->map.tile_size)
		{
			game->collectible.img->instances[idx].enabled = false;
			break ;
		}
		idx++;
	}
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
	if (next_tile == 'E'
		&& game->map.num_collectibles != game->map.total_collectibles)
		return (0);
	if (next_tile == 'C')
		handle_collectible(game, nx, ny);
	if (next_tile == 'E'
		&& game->map.num_collectibles == game->map.total_collectibles)
	{
		ft_putstr_fd("You win!\n", 1);
		close_window(game);
		return (1);
	}
	handle_player_move(game, nx, ny);
	return (1);
}
