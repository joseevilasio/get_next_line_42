/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:25:01 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 20:07:11 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*merge(char *s1, char *s2)
{
	char	*merge;

	if (!*s1 && !*s2)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	merge = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (merge);
}

static char	*putcache(char *content)
{
	char	*new_line;
	char	*new_cache;

	if (!content)
		return (NULL);
	new_line = ft_strchr(content, '\n');
	if (!new_line)
		return (NULL);
	new_line++;
	if (!*new_line)
		return (NULL);
	new_cache = ft_strdup(new_line);
	if (!new_cache)
		return (NULL);
	return (new_cache);
}

static char	*putline(char *content, char *cache)
{
	char	*new_content;
	size_t	size;

	if (!content)
		return (NULL);
	if (!*content)
	{
		free(content);
		return (NULL);
	}
	if (!cache)
		return (content);
	size = ft_strlen(content) - ft_strlen(cache);
	new_content = (char *) malloc((size + 1) * sizeof(char));
	if (!new_content)
	{
		free(content);
		free(cache);
		return (NULL);
	}
	ft_strlcpy(new_content, content, size + 1);
	free(content);
	return (new_content);
}

static char	*read_fd(int fd, char *cache, char *buffer, char *content)
{
	int	read_size;

	read_size = 1;
	while (!ft_strchr(buffer, '\n') && read_size != 0)
	{
		if (cache)
		{
			content = merge(content, cache);
			free(cache);
			cache = NULL;
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		buffer[read_size] = '\0';
		content = merge(content, buffer);
		if (!content)
			return (NULL);
	}
	free(buffer);
	return (content);
}

char	*get_next_line(int fd)
{
	char		*content;
	char		*buffer;
	static char	*cache;

	if (!cache)
		cache = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	content = (char *) malloc(sizeof(char));
	if (!content)
	{
		free(buffer);
		return (NULL);
	}
	*content = 0;
	content = read_fd(fd, cache, buffer, content);
	if (!content)
		return (NULL);
	cache = putcache(content);
	return (putline(content, cache));
}
