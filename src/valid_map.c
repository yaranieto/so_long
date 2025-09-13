/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:40 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 20:41:07 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
			return (0);
		i++;
	}
	map->width = len;
	map->height = i;
	return (1);
}

int	check_the_element(char **map, char c)
{
	int	y;
	int	x;
	int width;
	int count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		width = ft_strlen(map[y]);
		while (x < width)
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_all_elements(t_map *map)
{
	int	has_exit;
	int	has_player;
	int	has_collectible;

	has_exit = check_the_element(map->map, 'E');
	has_player = check_the_element(map->map, 'P');
	has_collectible = check_the_element(map->map, 'C');

	if (has_exit != 1 || has_player != 1 || has_collectible < 1)
		return (0);
	
	map->total_collectibles = has_collectible;
	return (1);
}

int	check_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1' &&
				map->map[i][j] != 'C' && map->map[i][j] != 'E' &&
				map->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == map->width - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_ber_extension(char *str1, char *str2, size_t n)
{
	size_t	len1;
	size_t	len2;
	
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 < n || len2 < n)
		return (1);
	return (ft_strncmp(str1 + len1 - n, str2, n));
}

void	check_extension(char *filename)
{
	if (check_ber_extension(filename, ".ber", 4) != 0)
		error_exit("Error: Map file must have .ber extension");
}
