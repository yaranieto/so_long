/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:14:43 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:13:34 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd((char *)message, 2);
	exit(1);
}

void	print_error(const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd((char *)message, 2);
}

void	ft_putstr_fd(const char *s, int fd)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	count_lines(char **map)
{
	int	count;

	count = 0;
	while (map && map[count])
		count++;
	return (count);
}

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
