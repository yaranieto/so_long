/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:44 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 21:40:14 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	static int	first_render = 1;
	int			y;
	int			x;

	if (!first_render)
		return;

	load_images(game);
	
	// Primero renderizamos todos los suelos
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

	// Luego renderizamos las paredes
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

	// Después los coleccionables
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

	// Luego la salida
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit.img, 
					x * game->map.tile_size, y * game->map.tile_size);
			x++;
		}
		y++;
	}

	// Finalmente el jugador, para que siempre esté en la capa superior
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player.img, 
					x * game->map.tile_size, y * game->map.tile_size);
			x++;
		}
		y++;
	}

	first_render = 0;
}
