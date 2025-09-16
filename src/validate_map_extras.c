/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_extras.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:40:00 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/16 10:54:52 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map_elements(t_map *map)
{
	if (count_map_elements(map, 'P') != 1)
		error_exit("Must have one player");
	if (count_map_elements(map, 'E') != 1)
		error_exit("Must have one exit");
	if (count_map_elements(map, 'C') < 1)
		error_exit("Must have at least one collectible");
	map->total_collectibles = count_map_elements(map, 'C');
}

void	check_extension(char *filename)
{
	if (check_ber_extension(filename, ".ber", 4) != 0)
		error_exit("Error: Map file must have .ber extension");
}
