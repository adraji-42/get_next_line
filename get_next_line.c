/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/24 19:10:12 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

boolean	ft_search(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_preparation(char *read_, char *buffer)
{
	*read_ = '\0';
	if (buffer[0])
	{
		ft_strmove(buffer);
		return ;
	}
	else
		*buffer = '\0';
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*read_;
	static char	buffer[BUFFER_SIZE + 1];
	boolean		lin_not_end;
	int			bytes_read;

	read_ = malloc(sizeof(char));
	if (!read_)
		return (NULL);
	ft_preparation(read_, buffer);
	lin_not_end = 1;
	while (lin_not_end)
	{
		tmp = read_;
		if (ft_search(buffer))
			lin_not_end = 0;
		read_ = ft_strjoin(tmp, buffer);
		if (lin_not_end)
		{
			free (tmp);
			if (!read_)
				return (NULL);
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (NULL);
			buffer[bytes_read] = '\0';
			if (!buffer[0])
			{
				if (read_[0])
					return (read_);\
				return (NULL);
			}
		}
	}
	return (read_);
}
