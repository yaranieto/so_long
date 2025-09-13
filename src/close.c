/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:12:09 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 21:43:53 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->floor.img);
	mlx_delete_image(game->mlx, game->player.img);
	mlx_delete_image(game->mlx, game->wall.img);
	mlx_delete_image(game->mlx, game->collectible.img);
	mlx_delete_image(game->mlx, game->exit.img);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(0);
}

int	close_game(t_game *game)
{
	int	y;

	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		ft_memdel(game->mlx);
	}
	if (game->map.map)
	{
		y = 0;
		while (game->map.map[y])
			ft_memdel(game->map.map[y++]);
		ft_memdel(game->map.map);
	}
	exit(0);
}
