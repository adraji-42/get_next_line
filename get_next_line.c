/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/12/01 10:36:07 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_preparation(char **buffer, ssize_t *byte, char **new_line)
{
	char	*line;

	*byte = 1;
	if (*buffer)
	{
		line = ft_strjoin("", *buffer);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_strdup("");
		*buffer = malloc((size_t)(BUFFER_SIZE + 1) * sizeof(char));
		if (!*buffer || !line)
			return (free(buffer), buffer = NULL, free(line), NULL);
		(*buffer)[0] = '\0';
	}
	*new_line = ft_strchr(*buffer, '\n');
	return (line);
}

char	*ft_line(int fd, char **new_line)
{
	char		*tmp;
	char		*line;
	static char	*buffer;
	ssize_t		byte_read;

	line = ft_preparation(&buffer, &byte_read, new_line);
	if (!line)
		return (NULL);
	while (!*new_line && byte_read > 0)
	{
		tmp = line;
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buffer), buffer = NULL, free(line), NULL);
		buffer[byte_read] = '\0';
		line = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!line)
			return (free(buffer), buffer = NULL, NULL);
		*new_line = ft_strchr(buffer, '\n');
	}
	if (!*new_line)
		return (free(buffer), buffer = NULL, line);
	ft_strcpy_rest(buffer, &new_line[0][1]);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	line = ft_line(fd, &new_line);
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}
