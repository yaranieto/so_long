/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:37:40 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/12 19:40:29 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map) // comprueba de ancho pero no de altura
{
	int	width;
	int	len;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	len = 1; // recorre la segunda línea del mapa para compararla con la primera(width)
	while (map[len])
	{
		if (ft_strlen(map[len]) != width)
			return (0);
		len++;
	}
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

int	check_all_elements(char **map)
{
	int	player;
	int	exit;
	int	collectable;

	player = check_the_element(map, 'P');
	exit = check_the_element(map, 'E');
	collectable = check_the_element(map, 'C');

	if (player != 1)
		return (0);
	if (exit != 1)
		return (0);
	if (collectable < 1)
		return (0);
	return (1);
}

int	check_chars(char **map)
{
	int	y;
	int x;
	int	width;

	y = 0;
	while (map[y])
	{
		x = 0;
		width = ft_strlen(map[y]);
		while (x < width)
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P' &&
				map[y][x] != 'E' && map[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_walls(char **map) //comprobar si la función está bien.
{
	int		width; // cantidad columnas
	int		height; // cantidad filas
	int		i;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
