/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:01 by josejunior        #+#    #+#             */
/*   Updated: 2024/05/01 23:09:03 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*file;
	char	*line;

	file = "/home/josejunior/get_next_line_42/43_with_nl";
	fd = open(file, O_RDONLY);
	i = 0;
	printf("[MAIN BUFFER SIZE = %d]", BUFFER_SIZE);
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
			i++;
			printf("[line - %d]%s", i, line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
