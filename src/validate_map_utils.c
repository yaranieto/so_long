/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:32:31 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 23:05:56 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_chars(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!ft_strchr("01CEP", map->map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	count_map_elements(t_map *map, char element)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
