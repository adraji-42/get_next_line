/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/29 15:44:21 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return_null(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s2 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (NULL);
}

char	*ft_preparation(char **buffer, ssize_t *byte)
{
	char	*ft;

	*byte = 1;
	if (*buffer)
	{
		ft = ft_strjoin("", *buffer);
		if (!ft)
			return (NULL);
	}
	else
	{
		ft = ft_strdup("");
		*buffer = malloc((size_t)(BUFFER_SIZE + 1) * sizeof(char));
		if (!*buffer)
			return (ft_return_null(ft, NULL));
		(*buffer)[0] = '\0';
	}
	return (ft);
}


char	*ft_line(int fd, char **new_line)
{
	char		*tmp;
	char		*ft;
	static char	*buffer;
	ssize_t		byte_read;

	ft = ft_preparation(&buffer, &byte_read);
	if (!ft)
		return (NULL);
	while (!(*new_line = ft_strchr(buffer, '\n')) && (byte_read = read(fd, buffer, BUFFER_SIZE)))
	{
		tmp = ft;
		if (byte_read < 0)
			return (ft_return_null(ft, buffer));
		buffer[byte_read] = '\0';
		ft = ft_strjoin(tmp, buffer);
		if (!ft)
			return (ft_return_null(tmp, buffer));
		free(tmp);
	}
	if (!*new_line)
		buffer = ft_return_null(buffer, NULL);
	else
		ft_strcpy_rest(buffer, &new_line[0][1]);
	return (ft);
}

char	*get_next_line(int fd)
{
	char		*ft;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	ft = ft_line(fd, &new_line);
	if (!ft || !*ft)
		return (ft_return_null(ft, NULL));
	return (ft);
}
