/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/17 00:48:41 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

boolean	ft_search(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			ft_strmove(s, &s[i], BUFFER_SIZE - i);
			return (1);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*read_;
	char		*buffer;
	boolean		lin_not_end;

	read_ = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !read_)
		return (NULL);
	read_[BUFFER_SIZE] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	lin_not_end = 1;
	while (lin_not_end)
	{
		buffer = read(fd, buffer, BUFFER_SIZE);
		if (ft_search(buffer))
			lin_not_end = 0;
		read_ = ft_strjoin(read_, buffer);
	}
}
