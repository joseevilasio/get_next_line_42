/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:01 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/28 22:26:54 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int				fd;
	char			*file;
	char			*line;

	file = "/home/josejunior/get_next_line_42/43_with_nl";
	fd = open(file, O_RDONLY);
	printf("fd ->%d\n", fd);
	if (fd > 0)
	{
		while (line)
		{
			line = get_next_line(fd);
			if (!line)
			{
				free(line);
				break;
			}
			printf("%s", line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
