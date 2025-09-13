/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:53 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/12 13:48:29 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_game *game)
{
	mlx_texture_t* tex;

	tex = mlx_load_png("textures/player.png");
	if (!tex)
		error_exit("Error loading player texture");
	game->img_player = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("textures/exit.png");
	if (!tex)
		error_exit("Error loading exit texture");
	game->img_exit = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("textures/wall.png");
	if (!tex)
		error_exit("Error loading wall texture");
	game->img_wall = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("textures/collectible.png");
	if (!tex)
		error_exit("Error loading collectible texture");
	game->img_collectible = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("textures/floor.png");
	if (!tex)
		error_exit("Error loading floor texture");
	game->img_floor = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	if (!game->img_player || !game->img_exit || !game->img_wall ||
		!game->img_collectible || !game->img_floor)
		error_exit("Error converting texture to image");
}


void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game*)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
}
