/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:45:00 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:33:15 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images_extra(t_game *game)
{
	load_collectible_image(game);
	load_floor_image(game);
}
