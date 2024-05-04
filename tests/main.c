/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:37:19 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 18:28:37 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_test = 1;

void	puttitle(char *file)
{
	int i = 0;
	char **temp = ft_split(file, '/');
	if (temp)
		printf("\n\033[1;35m CASE :: %s :: \033[0m\n", temp[2]);
	while(temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	
}

void	check(int fd, char *expected)
{
	int i = 0;
	char *return_= get_next_line(fd);
	if (expected == NULL)
	{
		if(return_ == NULL)
			i = 1;
	}
	else
	{
		if (!ft_strncmp(expected, return_, ft_strlen(expected)))
			i = 1;
	}
	if (i == 0)
		printf("[\033[1;31m%d -> TEST FAILED\033[0m] ", count_test);
	else
		printf("[\033[1;32m%d -> TEST PASSED\033[0m] ", count_test);
	free(return_);
	count_test++;
}

int main(void)
{
	/* case 1 */
	char *file = "./files/read_error.txt";
	puttitle(file);
	int fd = open(file, O_RDONLY);
	/* 1 */
	check(fd, "aaaaaaaaaa\n");
	close(fd);
	/* 2 */
	return (0);
}