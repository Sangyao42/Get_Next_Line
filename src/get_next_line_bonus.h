/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:21:05 by sawang            #+#    #+#             */
/*   Updated: 2022/11/22 22:02:35 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 4
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_read(int fd, ssize_t count);
char	*read_and_accumulate(int fd, char *offset_str);
char	*get_first_line(char *offset_str);
char	*get_offset_str(char *offset_str);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char const *s1);

#endif