/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:54:58 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:39:08 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *str1, char *str2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;
	if (len1 < n)
		n = len1;
	if (len2 < n)
		n = len2;
	return (ft_strncmp(str1 + len1 - n, str2 + len2 - n, n));
}

int	valid_map(t_map *map)
{
	if (!check_rectangular(map))
		return (0);
	if (!check_walls(map))
		return (0);
	if (!check_chars(map))
		return (0);
	if (!check_all_elements(map))
		return (0);
	return (1);
}

void	flood_fill(char **map, t_map map_info, int y, int x)
{
	if (x < 0 || y < 0 || x >= map_info.width || y >= map_info.height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, map_info, y + 1, x);
	flood_fill(map, map_info, y - 1, x);
	flood_fill(map, map_info, y, x + 1);
	flood_fill(map, map_info, y, x - 1);
}

int	check_access(char **map, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_map(t_map *map)
{
	if (!check_rectangular(map))
		error_exit("Map must be rectangular");
	if (!validate_map_chars(map))
		error_exit("Invalid characters in map");
	if (!validate_map_borders(map))
		error_exit("Map must be surrounded by walls");
	check_map_elements(map);
}
