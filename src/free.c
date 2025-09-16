/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:18:50 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/15 13:15:59 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_memdel(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

void	free_map(char **array)
{
	int	i;

	if (array != NULL)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
