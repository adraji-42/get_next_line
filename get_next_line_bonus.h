/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:29 by adraji            #+#    #+#             */
/*   Updated: 2025/12/19 15:50:31 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_nl(const char *s);
char	*ft_strchr_nl(const char *s);
char	*ft_strdup_nl(const char *s1);
void	ft_strcpy(char *dest, char *src);
char	*ft_strjoin_nl(char const *s1, const char *s2);

#endif
