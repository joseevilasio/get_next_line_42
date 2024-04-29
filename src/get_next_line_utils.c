/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:00:59 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/29 13:23:08 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	read_line(int fd, char *buffer, size_t size_buffer)
{
	size_t	i; //tamanho do que foi alocado em buffer
	size_t	size_read; //tamanho do que foi lido
	char	*chunk; //recebe char a char para alocar no buffer

	size_read = 0;
	i = 0;
	while(size_buffer != i)
	{
		size_read = read(fd, chunk, size_buffer); //ler
		if (size_read == 0) //se chegou ao fim
			break;
		buffer[i] = chunk; //aloca char em buffer
		i++;
	}
	buffer[i] = '\0';
	return (i);
}
