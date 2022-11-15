/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:03:38 by sawang            #+#    #+#             */
/*   Updated: 2022/11/15 18:59:30 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	char	*str_join;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str_join[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str_join[ft_strlen(s1) + i] = '\0';
	return (free(s1), str_join);
}

size_t	ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	str = (char *)s;
	s_len = ft_strlen(str);
	if ((char) c == 0)
		return (s_len);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		substr = (char *)malloc(1);
	else if (len > s_len)
		substr = (char *)malloc(s_len - (size_t)start + 1);
	else
		substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && (size_t)start < s_len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
