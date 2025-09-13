/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:12:09 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/12 14:35:12 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img_player);
	mlx_delete_image(game->mlx, game->img_wall);
	mlx_delete_image(game->mlx, game->img_floor);
	mlx_delete_image(game->mlx, game->img_exit);
	mlx_delete_image(game->mlx, game->img_collectible);
	mlx_terminate(game->mlx);
	exit(0);
}

int	close_game(t_game *game)
{
	int	y;

	#ifdef __linux__
	if (game->mlx)
		mlx_terminate(game->mlx);
	#endif

	if (game->mlx)
		ft_memdel(game->mlx);
	if (game->map.map)
	{
		y = 0;
		while (game->map.map[y])
			ft_memdel(game->map.map[y++]);
		ft_memdel(game->map.map);
	}
	exit(0);
}
