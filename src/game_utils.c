/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:50:00 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:32:51 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_player_move(t_game *game, int nx, int ny)
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
