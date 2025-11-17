/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:25 by adraji            #+#    #+#             */
/*   Updated: 2025/11/17 00:49:27 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	while (*s1)
		s[i++] = *(s1++);
	while (*s2)
		s[i++] = *(s2++);
	s[i] = '\0';
	free(s1);
	free(s2);
	return (s);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len)
		s[i] = s1[i++];
	s[i] = '\0';
	return s;
}

void	*ft_strmove(char *dest, const char *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	dest[n] = '\0';
	while (n > 0)
	{
		dest[n] = src[n];
		n--;
	}
	return (dest);
}
