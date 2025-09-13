/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:07:01 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 21:21:56 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Error\nUsage: ./so_long <map_file.ber>");
	
	check_extension(argv[1]);
	game.map.map = read_map(argv[1]);
	if (!game.map.map)
		error_exit("Error reading map");

	validate_map(&game.map);
	player_position(&game.map, &game);
	
	if (!validate_game(&game))
		error_exit("Error: Map is not playable - all collectibles and exit must be reachable");

	// Set tile size to make each tile 32x32 pixels
	game.map.tile_size = 64;

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

	lines = count_lines_file((char *) filename);
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
	while (i  < lines)
	{
		map[i] = read_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
}
int		count_lines_file(const char *filename)
{
	int		fd;
	int		lines;
	char	c;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines + 1);
}

char	*read_line(int fd)
{
	char	c;
	char	*line;
	int		ret;
	int		len;

	line = NULL;
	len = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret <= 0)
			break ;
		if (c == '\n')
			break ;
		line = add_char(line, c, &len);
		if (!line)
			return (NULL);
	}
	if (!line && ret <= 0)
		return (NULL);
	return (line);
}

char	*add_char(char *line, char c, int *len)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * (*len + 2));
	if (!new_line)
	{
		ft_memdel(line);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = c;
	new_line[i + 1] = '\0';
	ft_memdel(line);
	(*len)++;
	return (new_line);
}
