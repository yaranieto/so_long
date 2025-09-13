/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:53 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 23:22:21 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_texture_to_image(mlx_image_t *img, mlx_texture_t *tex)
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
			pixeldata = &tex->pixels[(y * tex->width + x)
				* tex->bytes_per_pixel];
			mlx_put_pixel(img, x, y, (pixeldata[0] << 24)
				| (pixeldata[1] << 16) | (pixeldata[2] << 8) | pixeldata[3]);
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
	game->player.img = mlx_new_image(game->mlx, game->map.tile_size,
			game->map.tile_size);
	if (!game->player.img)
		error_exit("Error creating player image");
	copy_texture_to_image(game->player.img, tex);
	mlx_delete_texture(tex);
}

void	load_images(t_game *game)
{
	load_player_image(game);
	load_exit_image(game);
	load_wall_image(game);
	load_images_extra(game);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
}
