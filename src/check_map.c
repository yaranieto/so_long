/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:40 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/15 17:16:23 by ynieto-s         ###   ########.fr       */
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
	int	i;
	int	j;
	int	width;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		width = ft_strlen(map[i]);
		while (j < width)
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_all_elements(t_map *map)
{
	int	exit;
	int	player;
	int	collectible;

	exit = check_the_element(map->map, 'E');
	player = check_the_element(map->map, 'P');
	collectible = check_the_element(map->map, 'C');
	if (exit != 1 || player != 1 || collectible < 1)
		return (0);
	map->total_collectibles = collectible;
	return (1);
}
