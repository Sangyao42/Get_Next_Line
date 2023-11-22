/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:41:30 by sawang            #+#    #+#             */
/*   Updated: 2023/11/21 21:20:52 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strchr(const char *s, int c);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char const *s1);
//memcpy
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif