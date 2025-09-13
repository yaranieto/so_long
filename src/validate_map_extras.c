/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_extras.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:40:00 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 23:17:45 by ynieto-s         ###   ########.fr       */
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
		error_exit("Must have exactly one player");
	if (count_map_elements(map, 'E') != 1)
		error_exit("Must have exactly one exit");
	if (count_map_elements(map, 'C') < 1)
		error_exit("Must have at least one collectible");
	map->total_collectibles = count_map_elements(map, 'C');
}

void	check_extension(char *filename)
{
	if (check_ber_extension(filename, ".ber", 4) != 0)
		error_exit("Error: Map file must have .ber extension");
}

/*
** Duplica el mapa dado en una nueva matriz terminada en NULL.
** Devuelve NULL en caso de fallo de memoria.
*/
static char	**dup_map(t_map *map)
{
	int		i;
	char	**copy;

	if (!map)
		return (NULL);
	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

/*
** validate_game: crea una copia del mapa, ejecuta flood_fill y 
comprueba accesos.
** Devuelve 1 si el mapa es válido, 0 si hay fallo o no es válido.
*/
int	validate_game(t_game *game)
{
	char	**map_copy;
	int		valid;
	int		i;

	if (!game)
		return (0);
	map_copy = dup_map(&game->map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->map, game->player_y, game->player_x);
	valid = check_access(map_copy, game->map.height, game->map.width);
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
	return (valid);
}
