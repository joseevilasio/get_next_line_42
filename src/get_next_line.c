/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:25:01 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/29 23:26:33 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	char	*end_line;
	char *cache;
	size_t	size;

	line = "";
	if (line)
	{
		while (buffer)
		{
			buffer = ft_buffer(fd);
			end_line = ft_strchr(buffer, '\n');
			if (end_line)
			{
				size = ft_strlen(end_line);
				cache = (char *) malloc(size * sizeof(char) + 1);
				line = ft_strjoin(line, (buffer - size));
				return (line);
			}
			else if (buffer)
				line = ft_strjoin(line, buffer);
		}
		return (line);
	}
	return (NULL);
}

