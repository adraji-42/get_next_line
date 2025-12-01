/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/12/01 14:40:30 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(int fd, char **buffer, char *line)
{
	char		*tmp;
	char		*new_line;
	ssize_t		byte_read;

	byte_read = 1;
	new_line = ft_strchr(*buffer, '\n');
	while (!new_line && byte_read > 0)
	{
		tmp = line;
		byte_read = read(fd, *buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(*buffer), free(line), (*buffer = NULL));
		(*buffer)[byte_read] = '\0';
		line = ft_strjoin(tmp, *buffer);
		free(tmp);
		if (!line)
			return (free(*buffer), *buffer = NULL, NULL);
		new_line = ft_strchr(*buffer, '\n');
	}
	if (!new_line)
		return (free(*buffer), *buffer = NULL, line);
	ft_strcpy_rest(*buffer, &new_line[1]);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer)
	{
		line = ft_strdup(buffer);
		if (!line)
			return (free(buffer), (buffer = NULL));
	}
	else
	{
		line = ft_strdup("");
		buffer = malloc(((size_t) BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer || !line)
			return (free(buffer), free(line), (buffer = NULL));
		buffer[0] = '\0';
	}
	line = ft_line(fd, &buffer, line);
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}
