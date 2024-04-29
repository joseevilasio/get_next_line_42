/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:25:01 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/28 23:38:52 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//BUFFER definido na linha de comando, se nao houver usar um padrao
	char	*buffer; // armazena o que foi lido
	size_t	size_buffer; //tamanho do que e para ser lido
	size_t	size_read;
	
	size_buffer = 42;
	size_read = 0;
	buffer = NULL;
	buffer = (char *) malloc(size_buffer * sizeof(char) + 1);
	if (buffer) //se ocorrer bem
	{
		size_read = read_line(fd, buffer, size_buffer);
		printf("\n[len=%ld]\n", size_read);
		if (size_read == 0)
			return (NULL);
		return (buffer);
	}
	return (NULL);
}
