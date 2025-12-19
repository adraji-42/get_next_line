/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:29 by adraji            #+#    #+#             */
/*   Updated: 2025/12/01 14:44:52 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_nl(const char *s);
char	*ft_strdup_nl(const char *s1);
char	*ft_strchr_nl(const char *s);
void	ft_strcpy(char *dest, char *src);
char	*ft_strjoin_nl(char const *s1, const char *s2);

#endif
