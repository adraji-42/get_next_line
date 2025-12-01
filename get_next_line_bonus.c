/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/12/01 10:59:07 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (free(*buffer), *buffer = NULL, free(line), NULL);
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
	static char	*buffer[1024];

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd])
	{
		line = ft_strdup(buffer[fd]);
		if (!line)
			return (free(buffer[fd]), (buffer[fd] = NULL));
	}
	else
	{
		line = ft_strdup("");
		buffer[fd] = malloc(((size_t) BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer[fd] || !line)
			return (free(buffer[fd]),buffer[fd] = NULL, free(line), NULL);
		(buffer[fd])[0] = '\0';
	}
	line = ft_line(fd, &buffer[fd], line);
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}
