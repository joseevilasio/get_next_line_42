/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:01 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/05 23:04:10 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	*teste(int fd)
{
	int	buffer = 1;
	char str[10];
	int size = 0;
	int size_read = 1;
	char compile[1000];
	

	// char *file = "/home/josejunior/get_next_line_42/43_with_nl";
	// int fd = open(file, O_RDONLY);
	// while (size_read > 0)
	// {
	int i = 0;
	// free(compile);
	while (compile[i - 1] != '\n')
	{
		size_read = read(fd, str, buffer);
		size += size_read;
		if (size_read == 0)
			break;
		compile[i] = *str;
		i++;
		// printf("carregado -> %s| size = %d\n", str, size);
	}
	compile[i] = '\0';
	// printf("compile -> %s", compile);
	return (compile);
	// }
	// close(fd);
	return (0);
}
