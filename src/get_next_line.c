/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:25:01 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/02 13:42:28 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_putcache(char *buffer, char *cache)
{
	char *ptr_buffer;
	int	i;

	i = 0;
	ptr_buffer = ft_strchr(buffer, '\n');
	if (ptr_buffer)
	{
		ptr_buffer++;
		cache = (char *) malloc(ft_strlen(ptr_buffer) * sizeof(char) + 1);
		while (ptr_buffer[i])
		{
			cache[i] = ptr_buffer[i];
			i++;
		}
		cache[i] = '\0';
	}
	if (*buffer)
	{
		if (!cache)
			return (buffer);
		else if (!*(cache + 1))
		{
			cache = NULL;
			return (buffer);
		}
		ft_strlcpy(buffer, buffer, (ft_strlen(buffer) - ft_strlen(cache)) + 1);
		return (buffer);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			read_size;
	char		*buffer;
	char		*content;
	static char	*cache;

	printf("[FT BUFFER SIZE = %d]", BUFFER_SIZE);
	read_size = 1;
	buffer = "";
	cache = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || read(fd, &content, 0) < 0)
		return (NULL);
	content = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!content)
		return (NULL);
	while (!ft_strchr(content, '\n') && read_size != 0)
	{
		if (cache)
		{
			printf("[cache -> %s]", cache);
			buffer = ft_strjoin(buffer, cache);
			free(cache);
		}
		read_size = read(fd, content, BUFFER_SIZE);
		content[read_size] = '\0';
		buffer = ft_strjoin(buffer, content);
	}
	free(content);
	buffer = ft_putcache(buffer, cache);
	return (buffer);
}
