/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:25:01 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/01 01:02:32 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif //BUFFER_SIZE
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			read_size;
	char		*buffer;
	char		*content;
	static char	*cache;

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
			buffer = ft_strjoin(buffer, cache);
		read_size = read(fd, content, BUFFER_SIZE);
		content[read_size] = '\0';
		buffer = ft_strjoin(buffer, content);
	}
	buffer = ft_putcache(buffer, cache, content, read_size);
	return (buffer);
}
