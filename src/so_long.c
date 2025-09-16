/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:07:01 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/16 14:38:19 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map_file.ber>");
	check_extension(argv[1]);
	game.map.map = read_map(argv[1]);
	if (!game.map.map)
		error_exit("Error reading map");
	validate_map(&game.map);
	player_position(&game.map, &game);
	if (!playable_game(&game))
		error_exit("Error: all collectibles and exit must be reachable");
	start_game(&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map.map);
	return (0);
}

char	**read_map(const char *filename)
{
	int		fd;
	int		lines;
	char	**map;

	lines = count_lines_file((char *)filename);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_memdel(map);
		return (NULL);
	}
	build_map(fd, map, lines);
	close(fd);
	return (map);
}

void	build_map(int fd, char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		map[i] = read_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
}
