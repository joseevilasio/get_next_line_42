/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:00:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/29 23:21:54 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif //BUFFER_SIZE

char	*ft_buffer(int fd)
{
	size_t	size_read;
	char	*buffer;

	buffer = NULL;
	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer)
	{
		size_read = 0;
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read > 0)
		{
			buffer[size_read] = '\0';
			return (buffer);
		}
		free(buffer);
	}
	return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	c = c % 256;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && dest)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	size;
	unsigned int	size_s1;
	unsigned int	size_s2;

	if (s1 && s2)
	{
		size_s1 = ft_strlen((char *) s1);
		size_s2 = ft_strlen((char *) s2);
		size = size_s1 + size_s2;
		str = (char *) malloc(size * sizeof(char) + 1);
		if (str)
		{
			ft_strlcpy(str, (char *)s1, size_s1 + 1);
			ft_strlcpy(str + size_s1, (char *)s2, size_s2 + 1);
			return (str);
		}
	}
	return (NULL);
}

// unsigned int	ft_line(int fd, char *line)
// {
// 	char			*buffer;
// 	// unsigned int	newline;
	
// 	// newline = 0;
// 	if (line)
// 	{
// 		while (buffer)
// 		{
// 			buffer = ft_buffer(fd);
// 			if (buffer)
// 				line = ft_strjoin(line, buffer);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }
