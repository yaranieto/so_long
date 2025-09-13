/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:44 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:28:16 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floors(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx, game->floor.img,
				x * game->map.tile_size, y * game->map.tile_size);
			x++;
		}
		y++;
	}
}

static void	render_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall.img,
					x * game->map.tile_size, y * game->map.tile_size);
			x++;
		}
		y++;
	}
}

static void	render_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collectible.img,
					x * game->map.tile_size, y * game->map.tile_size);
			x++;
		}
		y++;
	}
}

static void	render_exit_and_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit.img,
					x * game->map.tile_size, y * game->map.tile_size);
			if (game->map.map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player.img,
					x * game->map.tile_size, y * game->map.tile_size);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	static int	first_render = 1;

	if (!first_render)
		return ;
	load_images(game);
	render_floors(game);
	render_walls(game);
	render_collectibles(game);
	render_exit_and_player(game);
	first_render = 0;
}
