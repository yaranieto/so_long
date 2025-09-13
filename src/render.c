/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:44 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/11 16:58:28 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile; // baldosa o azulejo

	y = 0;
	while(game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			tile = game->map.map[y][x];
			mlx_image_to_window(game->mlx, game->img_floor,
			x * game->img_width, y * game->img_height);
			render_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->img_wall, x * game->img_width,
		y * game->img_height);
	else if (tile == 'P')
		mlx_image_to_window(game->mlx, game->img_player, x * game->img_width,
		y * game->img_height);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->img_collectible, x *
			game->img_width, y * game->img_height);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->img_collectible, x *
		game->img_width, y * game->img_height);
}
