/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:15:06 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/16 14:53:45 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Se eliminó copy_texture_to_image ya que ahora está en events.c

void	load_wall_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/wall.png");
	if (!tex)
		error_exit("Error loading wall texture");
	game->wall.img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->wall.img)
		error_exit("Error creating wall image");
	copy_texture_to_image(game->wall.img, tex);
	mlx_delete_texture(tex);
}

void	load_exit_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/exit.png");
	if (!tex)
		error_exit("Error loading exit texture");
	game->exit.img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->exit.img)
		error_exit("Error creating exit image");
	copy_texture_to_image(game->exit.img, tex);
	mlx_delete_texture(tex);
}

void	load_collectible_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/collectible.png");
	if (!tex)
		error_exit("Error loading collectible texture");
	game->collectible.img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->collectible.img)
		error_exit("Error creating collectible image");
	copy_texture_to_image(game->collectible.img, tex);
	mlx_delete_texture(tex);
}

void	load_floor_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/floor.png");
	if (!tex)
		error_exit("Error loading floor texture");
	game->floor.img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->floor.img)
		error_exit("Error creating floor image");
	copy_texture_to_image(game->floor.img, tex);
	mlx_delete_texture(tex);
}
