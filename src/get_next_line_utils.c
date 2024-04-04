/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:20:14 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/04 13:24:01 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif //BUFFER_SIZE

char	*ft_read_fd(int fd)
{
	char	*content;
	ssize_t		r;

	content = NULL;
	if (content == NULL && fd > 0)
	{
		content = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
		r = read(fd, content, BUFFER_SIZE);
		if (r < 0 || content == NULL)
		{
			free(content);
			return (NULL);
		}
	}
	return (content);
}

unsigned int	ft_strlen_line(const char *str)
{
	unsigned int	i;
	char	*ptr_str;

	i = 0;
	ptr_str = (char *) str;
	while (ptr_str[i] && ptr_str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(ft_strlen_line(src) * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	while (src[i] != '\0' && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_line(char *content)
{
	char		*line;
	int			i;
	static int	size;

	i = 0;
	if (!size)
		size = 0;
	content += size;
	if (content[i])
	{
		line = ft_strdup(content);
		size += ft_strlen_line(content) + 1;
		return (line);
	}
	return (NULL);
}
