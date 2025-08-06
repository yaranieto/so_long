/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:07:01 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/08/06 16:40:04 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		program;

	program = 1;
	if (argc != 2)
		error_exit("Only 2 args");
	if (ft_rstrncmp(argv[1], ".ber", 4))
		error_exit("Map must be a file .ber");
	map = read_map(argv[1]);
	if (!map)
		error_exit("Error reading the map");
	if (!is_valid_map(map))
		error_exit("Invalid map");
	init_minilibX();
	init_structure();
	init_grafics();
	init_other();
	draw_map();
	init_game();
	free_resources();
	return (0);
}
void	init_game()
{
	int		program;
	char	event;

	program = 1;
	while (program == 1)
	{
		wait_event();
		if (event)
		{
			move_player();
			draw_again();
		}
		if (event)
			close_event();
	}
}
char	read_map(const char *filename)
{
	int			fd;
	char		*line;
	ssize_t		bytes_read;
	char		*buffer;
	size_t		buffer_size;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, buffer, buffer_size);
	while (bytes_read < 0)
	{
		bytes_read = read(fd, buffer, buffer_size);
		if (bytes_read != -1);
		
	}
	close(fd);
}

void	free_map(char **map, int num_lines)
{
	int	i;
	int	num_lines;

	i = 0;
	while(i < num_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}