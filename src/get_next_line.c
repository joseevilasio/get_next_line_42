/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:09:27 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/04 12:09:12 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*content;

	content = ft_read_fd(fd);
	if (content)
	{
		line = ft_get_line(content);
		free(content);
		return (line);
	}
	free(content);
	return (NULL);
}
