/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:23:26 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/16 14:49:57 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_exit_position(t_game *game, int *exit_x, int *exit_y)
{
	int	y;
	int	x;

	y = 0;
	*exit_x = -1;
	while (y < game->map.height && *exit_x == -1)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'E')
			{
				*exit_x = x;
				*exit_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_remaining_coins(char **map, int height, int width)
{
	int	i;
	int	x;

	i = 0;
	while (i < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[i][x] == 'C')
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	check_coins_accessibility(t_game *game, int exit_x, int exit_y)
{
	char	**map_copy;
	int		valid;
	t_map	map_info;

	map_copy = dup_map(&game->map);
	if (!map_copy)
		return (0);
	if (exit_x != -1)
		map_copy[exit_y][exit_x] = '1';
	map_info.width = game->map.width;
	map_info.height = game->map.height;
	flood_fill(map_copy, &map_info, game->player_y, game->player_x);
	valid = check_remaining_coins(map_copy, game->map.height, game->map.width);
	free_map(map_copy);
	return (valid);
}

int	check_exit_accessibility(t_game *game, int exit_x, int exit_y)
{
	char	**map_copy;
	int		valid;
	int		i;
	t_map	map_info;

	if (exit_x == -1)
		return (0);
	map_copy = dup_map(&game->map);
	if (!map_copy)
		return (0);
	map_info.width = game->map.width;
	map_info.height = game->map.height;
	flood_fill(map_copy, &map_info, game->player_y, game->player_x);
	valid = (map_copy[exit_y][exit_x] == 'F');
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
	return (valid);
}

int	playable_game(t_game *game)
{
	int	exit_x;
	int	exit_y;

	if (!game)
		return (0);
	if (!find_exit_position(game, &exit_x, &exit_y))
		return (0);
	if (!check_coins_accessibility(game, exit_x, exit_y))
		return (0);
	if (!check_exit_accessibility(game, exit_x, exit_y))
		return (0);
	return (1);
}
