/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:54:58 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:13:34 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Prototipos de funciones auxiliares
int validate_map_chars(t_map *map);
int validate_map_borders(t_map *map);
int count_map_elements(t_map *map, char element);

// revisar si la funcion está bien
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

int		valid_map(t_map *map)
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
	// 1. Comprobar limites, no salirse del mapa
	if (x < 0 || y < 0 || x >= map_info.width || y >= map_info.height)
		return ;
	// 2. Comprobar si la posición es pared o ya visitada
	if(map[y][x] == '1' || map[y][x] == 'F')
		return ;
	// 3. Marcar como visitado para no repetir
	map[y][x] = 'F';
	// 4. Llamada recursiva a las 4 direcciones (arriba, abajo, izq, dcha)
	flood_fill(map, map_info, y + 1, x);
	flood_fill(map, map_info, y - 1, x);
	flood_fill(map, map_info, y, x + 1);
	flood_fill(map, map_info, y, x - 1);
}
// Revisa si hay coleccionables o salida de inaccesibles en el mapa marcado
int	check_access(char ** map, int height, int width)
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
				return (0); // Hay coleccionable o salida inaccesible
			x++;
		}
		y++;
	}
	return (1);
}
// Función completa para validar la jugabilidad con flood_fill

int	validate_game(t_game *game)
{
	char	**map_copy;
	int		i;
	int		valid;

	map_copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!map_copy)
		return (0);

	i = 0;
	while (i < game->map.height)
	{
		map_copy[i] = ft_strdup(game->map.map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (0);
		}
		i++;
	}
	map_copy[game->map.height] = NULL;

	// Do flood fill starting from player position
	flood_fill(map_copy, game->map, game->player_y, game->player_x);
	valid = check_access(map_copy, game->map.height, game->map.width);

	// Clean up
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);

	return (valid);
}

static void	check_map_elements(t_map *map)
{
	if (count_map_elements(map, 'P') != 1)
		error_exit("Must have exactly one player");
	if (count_map_elements(map, 'E') != 1)
		error_exit("Must have exactly one exit");
	if (count_map_elements(map, 'C') < 1)
		error_exit("Must have at least one collectible");
	map->total_collectibles = count_map_elements(map, 'C');
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
