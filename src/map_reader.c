/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:30:00 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/13 22:34:24 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_file(const char *filename)
{
	int		fd;
	int		lines;
	char	c;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines + 1);
}

char	*read_line(int fd)
{
	char	c;
	char	*line;
	int		ret;
	int		len;

	line = NULL;
	len = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret <= 0)
			break ;
		if (c == '\n')
			break ;
		line = add_char(line, c, &len);
		if (!line)
			return (NULL);
	}
	if (!line && ret <= 0)
		return (NULL);
	return (line);
}

char	*add_char(char *line, char c, int *len)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * (*len + 2));
	if (!new_line)
	{
		ft_memdel(line);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = c;
	new_line[i + 1] = '\0';
	ft_memdel(line);
	(*len)++;
	return (new_line);
}
