/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:25 by adraji            #+#    #+#             */
/*   Updated: 2025/12/19 15:52:23 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_nl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	len += (s[len] == '\n');
	return (len);
}

char	*ft_strdup_nl(const char *s1)
{
	size_t	i;
	char	*s;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen_nl(s1);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strchr_nl(const char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	if (!dest)
		return ;
	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin_nl(const char *s1, const char *s2)
{
	char	*s;
	size_t	len;
	size_t	i[2];

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_nl(s2);
	s = malloc(sizeof(char) * (ft_strlen_nl(s1) + len + 1));
	if (!s)
		return (NULL);
	i[0] = 0;
	while (i[0] < len)
	{
		s[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[1] = 0;
	while (i[1] < len)
		s[i[0]++] = s2[i[1]++];
	s[i[0]] = '\0';
	return (s);
}
