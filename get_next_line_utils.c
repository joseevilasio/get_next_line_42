/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:20:14 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/05 19:37:36 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, int BUFFER_SIZE)
{
	char	*content_fd;
	ssize_t	size_fd;

	if (fd < 0)
		return (NULL);
	content_fd = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!content_fd)
		return (NULL);
	size_fd = read(fd, content_fd, BUFFER_SIZE);
	if (size_fd <= 0)
	{
		free(content_fd);
		return (NULL);
	}
	return (content_fd);
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0 && dest != (void *)0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
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

char	*ft_get_line(char *content)
{
	static char	*current_content;
	char		*end_line;
	char		*line;
	int			size;

	if (!current_content)
		current_content = content;
	if (current_content == NULL || *current_content == '\0')
		return (NULL);
	end_line = ft_strchr(current_content, '\n');
	if (end_line)
		size = (end_line + 1) - current_content;
	else
		size = ft_strlen(current_content);
	line = (char *) malloc(size * sizeof(char) + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(line, current_content, size + 1);
	if (end_line)
		current_content = end_line + 1;
	else
		current_content += size;
	return (line);
}
