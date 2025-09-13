/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:53 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:14:18 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_texture_to_image(mlx_image_t *img, mlx_texture_t *tex)
{
	uint32_t	x;
	uint32_t	y;
	uint8_t		*pixeldata;

	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			pixeldata = &tex->pixels[(y * tex->width + x) * tex->bytes_per_pixel];
			mlx_put_pixel(img, x, y, (pixeldata[0] << 24) | (pixeldata[1] << 16)
				| (pixeldata[2] << 8) | pixeldata[3]);
			x++;
		}
		y++;
	}
}

static void	load_player_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/player.png");
	if (!tex)
		error_exit("Error loading player texture");
	game->player.img = mlx_new_image(game->mlx, game->map.tile_size, game->map.tile_size);
	if (!game->player.img)
		error_exit("Error creating player image");
	copy_texture_to_image(game->player.img, tex);
	mlx_delete_texture(tex);
}

static void	load_exit_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/exit.png");
	if (!tex)
		error_exit("Error loading exit texture");
	game->exit.img = mlx_new_image(game->mlx, game->map.tile_size, game->map.tile_size);
	if (!game->exit.img)
		error_exit("Error creating exit image");
	copy_texture_to_image(game->exit.img, tex);
	mlx_delete_texture(tex);
}

static void	load_wall_image(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/wall.png");
	if (!tex)
		error_exit("Error loading wall texture");
	game->wall.img = mlx_new_image(game->mlx, game->map.tile_size, game->map.tile_size);
	if (!game->wall.img)
		error_exit("Error creating wall image");
	copy_texture_to_image(game->wall.img, tex);
	mlx_delete_texture(tex);
}

void	load_images(t_game *game)
{
	load_player_image(game);
	load_exit_image(game);
	load_wall_image(game);
	load_images_extra(game);
}

void	load_images_extra(t_game *game)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png("textures/collectible.png");
	if (!tex)
		error_exit("Error loading collectible texture");
	game->collectible.img = mlx_new_image(game->mlx, game->map.tile_size, game->map.tile_size);
	if (!game->collectible.img)
		error_exit("Error creating collectible image");
	copy_texture_to_image(game->collectible.img, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("textures/floor.png");
	if (!tex)
		error_exit("Error loading floor texture");
	game->floor.img = mlx_new_image(game->mlx, game->map.tile_size, game->map.tile_size);
	if (!game->floor.img)
		error_exit("Error creating floor image");
	copy_texture_to_image(game->floor.img, tex);
	mlx_delete_texture(tex);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 1, 0);
}

void	hook(void *param)
{
	(void)param;
	// Implementación vacía para evitar error de enlace
}
