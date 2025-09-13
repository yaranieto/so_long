/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:49 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/12 14:35:12 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init(800, 600, "So long", false);
	if (!game->mlx)
		error_exit("Error init Minilibx");
	game->window = mlx_init(game->map.width * game->img_width,
	game->map.height * game->img_height, "so_long", false);
	if (!game->window)
		error_exit("Error opening a new window");
	load_images(game);
	render_map(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->window, close_window, game);
	mlx_loop(game->mlx);
}

int	move_player(t_game *game, int dx, int dy) // Quitar una linea
{
	int		nx;
	int		ny;
	char	next_tile;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	next_tile = game->map.map[ny][nx];
	if (next_tile == '1')
		return (0);
	if (next_tile == 'C')
	{	
		game->map.map[ny][nx] = '0';
		game->map.num_collectibles++;
	}
	if (next_tile == 'E')
	{
		if (game->map.num_collectibles == game->map.total_collectibles)
		{
			ft_putstr_fd("You win!\n", 1);
			close_window(game);
		}
	}
	else
		return (0);
	player_steps(game, nx, ny);
	return (1);
}


int	player_steps(t_game *game, int nx, int ny)
{
	char	*steps_str;

	game->map.map[game->player_y][game->player_x] = '0'; // Aqui se borra la posición anterior del jugador
	game->player_x = nx;
	game->player_y = ny;
	game->map.map[ny][nx] = 'P';
	game->steps++;
	steps_str = ft_itoa(game->steps);
	if (!steps_str)
		error_exit("Error converting steps to string");
	ft_putstr_fd("Steps: ", 1);
	ft_putstr_fd(steps_str, 1);
	ft_putstr_fd("\n", 1);
	ft_memdel(steps_str);
	render_map(game);
	return (0);
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
				game->img_width = 32;
				game->img_height = 32;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: player not found in map");
}
