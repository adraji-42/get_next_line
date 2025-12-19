/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:25 by adraji            #+#    #+#             */
/*   Updated: 2025/12/12 09:03:14 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	len = ft_strlen(s1);
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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
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
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s2);
	str = malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
