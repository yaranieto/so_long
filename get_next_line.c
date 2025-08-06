/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:04:14 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/08/06 16:44:37 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef BUFFER_SIZE
# define  BUFFER_SIZE 42
#endif

char	*trim_before_newline(char *input_str)
{
	char	*trimmed_str;
	char	*newline_ptr;
	int		len;

	newline_ptr = ft_strchr(input_str, '\n');
	if (!newline_ptr)
	{
		trimmed_str = NULL;
		return (free_buffer(&input_str));
	}
	else
		len = (newline_ptr - input_str) + 1;
	if (!input_str[len])
		return (free_buffer(&input_str));
	trimmed_str = ft_substr(input_str, len, ft_strlen(input_str) - len);
	free_buffer(&input_str);
	if (!trimmed_str)
		return (NULL);
	return (trimmed_str);
}

char	*extract_line(char *input_str)
{
	char	*extracted_line;
	char	*newline_ptr;
	int		len;

	newline_ptr = ft_strchr(input_str, '\n');
	len = (newline_ptr - input_str) + 1;
	extracted_line = ft_substr(input_str, 0, len);
	if (!extracted_line)
		return (NULL);
	return (extracted_line);
}

char	*read_buffer(int fd, char *buffer)
{
	int		bytes_read;
	char	*new_buffer;

	bytes_read = 1;
	new_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_buffer)
		return (free_buffer(&new_buffer));
	new_buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(new_buffer, '\n'))
	{
		bytes_read = read (fd, new_buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			new_buffer[bytes_read] = '\0';
			buffer = ft_strjoin(buffer, new_buffer);
		}
	}
	free(new_buffer);
	if (bytes_read == -1)
		return (free_buffer(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = read_buffer (fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
		return (free_buffer(&buffer));
	buffer = trim_before_newline(buffer);
	return (line);
}

char	*free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}
