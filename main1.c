/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:37:19 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/03 12:37:22 by joneves-         ###   ########.fr       */
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

	file = "./43_with_nl";
	fd = open(file, O_RDONLY);
	i = 0;
	printf("[MAIN BUFFER SIZE = %d]\n", BUFFER_SIZE);
	if (fd > 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			i++;
			printf("[line - %d]%s", i, line);
			free(line);
			line = get_next_line(fd);
		}
		free(line);
	}
	close(fd);
	return (0);
}
