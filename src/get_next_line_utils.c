/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:20:14 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/04 19:44:07 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif //BUFFER_SIZE

char	*ft_read_fd(int fd)
{
	char		*content_fd;
	ssize_t		size_fd;

	if (fd < 0)
		return (NULL);
	content_fd = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!content_fd)
		return (NULL);
	size_fd = read(fd, content_fd, BUFFER_SIZE);
	if (size_fd < 0)
	{
		free(content_fd);
		return (NULL);
	}
	content_fd[size_fd] = '\0';
	return (content_fd);
}

unsigned int	ft_line_len(const char *str)
{
	unsigned int	i;
	char			*ptr_str;

	i = 0;
	ptr_str = (char *) str;
	while (ptr_str[i] && ptr_str[i] != '\n')
		i++;
	return (i);
}

char	*ft_get_line(char *content)
{
	static char	*current_content;
	char		*line;
	int			i;

	i = 0;
	if (!current_content)
		current_content = content;
	if (current_content == NULL || *current_content == '\0')
		return (NULL);
	else
	{
		line = (char *) malloc(ft_line_len(current_content) * sizeof(char) + 1);
		if (!line)
		{
			free(line);
			return (NULL);
		}
		while (*current_content && *current_content != '\n')
		{
			line[i] = *current_content;
			i++;
			current_content++;
		}
		if (*current_content == '\n')
			current_content++;
		line[i] = '\0';
		return (line);
	}
}
