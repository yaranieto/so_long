/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:07:13 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/08/06 16:42:37 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fcntl.h>
#include <stdio.h>
#include <aio.h>
#include <stdlib.h>
#include <unistd.h>
// Estructura del mapa.
typedef struct s_map
{
	char	**map;
	int		weight;
	int		height;
	int		num_collect;
	int		num_exit;
	
}	t_map;

//Estructura sobre el juego y el jugador.
typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	map;
	int		player_x;
	int		player_y;
	int		moves;
	int		**image;
}	t_game;
void	init_game();
char	read_map(const char *filename);
int		ft_rstrncmp(const char *str1, const char *str2, size_t n);
char	*read_buffer(int fd, char *buffer);
char	*free_buffer(char **buffer);
