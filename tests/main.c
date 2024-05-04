/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:37:19 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/04 20:03:37 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
# ifndef VERBOSE
#  define VERBOSE 0
# endif //VERBOSE

int count_test = 0;
int count_case = 0;

void	puttitle(char *file)
{
	int i = 0;
	count_case++;
	char **temp = ft_split(file, '/');
	if (temp)
		printf("\n\033[1;35m CASE %d :: %s :: \033[0m\n", count_case, temp[2]);
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
	count_test++;
	char *return_= get_next_line(fd);
	if (expected == NULL)
	{
		if(return_ == NULL)
			i = 1;
	}
	else
	{
		if (return_)
		{
			if (!ft_strncmp(expected, return_, ft_strlen(expected)))
				i = 1;
		}
	}
	if (i == 0)
		printf("[\033[1;31m%d -> TEST FAILED\033[0m] ", count_test);
	else
		printf("[\033[1;32m%d -> TEST PASSED\033[0m] ", count_test);
	if (VERBOSE == 1)
	{
		printf("\n GNL RETURN\n%s", return_);
		printf("\n GNL EXPECTED\n%s", expected);
	}
	free(return_);
}

int main(void)
{
	char *file;
	int fd;
	
	printf("%d", BUFFER_SIZE);
	if (VERBOSE == 1)
		printf("\n\033[1;36m---- VERBOSE MODE -----\033[0m");
	/* case 1 */
	file = "./files/empty";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 1 */
	check(fd, NULL);
	close(fd);
	
	/* case 2 */
	file = "./files/error_fd";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 2 */
	check(fd, NULL);
	close(fd);
	
	/* case 3 */
	file = "./files/empty_multiple_newlines";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 3 */
	check(fd, "\n");
	/* 4 */
	check(fd, "\n");
	/* 5 */
	check(fd, "\n");
	/* 6 */
	check(fd, "\n");
	/* 7 */
	check(fd, NULL);
	close(fd);
	
	/* case 4 */
	file = "./files/multiple_newlines";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 8 */
	check(fd, "aaaaaaaaaa\n");
	/* 9 */
	check(fd, "bbbbbbbbbb\n");
	/* 10 */
	check(fd, "cccccccccc\n");
	/* 11 */
	check(fd, "dddddddddd\n");
	/* 12 */
	check(fd, "eeeeeeeeee\n");
	/* 13 */
	check(fd, "ffffffffff");
	/* 14 */
	check(fd, NULL);
	close(fd);

	/* case 5 */
	file = "./files/one_line";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 15 */
	check(fd, "O guia do mochileiro da galáxia: onde as toalhas são sagradas, os golfinhos são inteligentes e a resposta para a vida, o universo e tudo mais é... 42. Não se esqueça de levar sua toalha!");
	/* 16 */
	check(fd, NULL);
	close(fd);

	/* case 6 */
	file = "./files/one_big_line";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 17 */
	check(fd, "In the vast and infinite cosmos of the known universe, where stars dance to the rhythm of the celestial spheres, and planets weave tales in the starry skies, an epic journey awaits those brave enough to venture into the pages of The Hitchhiker's Guide to the Galaxy. Enter the depths of outer space and discover a world of absurdities and wonders, where towels are revered as lucky charms, dolphins are wise counselors, and the number 42 is the cosmic secret that permeates all existence. Get ready to embark on this intergalactic adventure that defies logic and transcends the boundaries of the imaginable!");
	close(fd);

	/* case 7 */
	file = "./files/multiple_big_newlines";
	puttitle(file);
	fd = open(file, O_RDONLY);
	/* 18 */
	check(fd, "In the vast and infinite cosmos of the known universe, where stars dance to the rhythm of the celestial spheres, and planets weave tales in the starry skies, an epic journey awaits those brave enough to venture into the pages of The Hitchhiker's Guide to the Galaxy. Enter the depths of outer space and discover a world of absurdities and wonders, where towels are revered as lucky charms, dolphins are wise counselors, and the number 42 is the cosmic secret that permeates all existence. Get ready to embark on this intergalactic adventure that defies logic and transcends the boundaries of the imaginable!\n");
	/* 19 */
	check(fd, "In the vast and infinite cosmos of the known universe, where stars dance to the rhythm of the celestial spheres, and planets weave tales in the starry skies, an epic journey awaits those brave enough to venture into the pages of The Hitchhiker's Guide to the Galaxy. Enter the depths of outer space and discover a world of absurdities and wonders, where towels are revered as lucky charms, dolphins are wise counselors, and the number 42 is the cosmic secret that permeates all existence. Get ready to embark on this intergalactic adventure that defies logic and transcends the boundaries of the imaginable!\n");
	/* 20 */
	check(fd, "In the vast and infinite cosmos of the known universe, where stars dance to the rhythm of the celestial spheres, and planets weave tales in the starry skies, an epic journey awaits those brave enough to venture into the pages of The Hitchhiker's Guide to the Galaxy. Enter the depths of outer space and discover a world of absurdities and wonders, where towels are revered as lucky charms, dolphins are wise counselors, and the number 42 is the cosmic secret that permeates all existence. Get ready to embark on this intergalactic adventure that defies logic and transcends the boundaries of the imaginable!\n");
	/* 21 */
	check(fd, "In the vast and infinite cosmos of the known universe, where stars dance to the rhythm of the celestial spheres, and planets weave tales in the starry skies, an epic journey awaits those brave enough to venture into the pages of The Hitchhiker's Guide to the Galaxy. Enter the depths of outer space and discover a world of absurdities and wonders, where towels are revered as lucky charms, dolphins are wise counselors, and the number 42 is the cosmic secret that permeates all existence. Get ready to embark on this intergalactic adventure that defies logic and transcends the boundaries of the imaginable!\n");
	/* 22 */
	check(fd, "In the vast and infinite cosmos of the known universe, where stars dance to the rhythm of the celestial spheres, and planets weave tales in the starry skies, an epic journey awaits those brave enough to venture into the pages of The Hitchhiker's Guide to the Galaxy. Enter the depths of outer space and discover a world of absurdities and wonders, where towels are revered as lucky charms, dolphins are wise counselors, and the number 42 is the cosmic secret that permeates all existence. Get ready to embark on this intergalactic adventure that defies logic and transcends the boundaries of the imaginable!");
	/* 23 */
	check(fd, NULL);
	close(fd);
	
	/* case 8 */
	file = "./files/stdin";
	puttitle(file);
	fd = 0;
	/* 24 */
	check(fd, "Hello!");
	close(fd);

	/* case 9 */
	file = "./files/multiple_fd";
	puttitle(file);
	int fd1 = open("./files/fd1", O_RDONLY);
	int fd2 = open("./files/fd2", O_RDONLY);
	int fd3 = open("./files/fd3", O_RDONLY);
	/* 24 */
	check(fd1, "a\n");
	/* 24 */
	check(fd2, "123\n");
	/* 24 */
	check(fd3, "another\n");
	/* 24 */
	check(fd1, "b\n");
	/* 24 */
	check(fd2, "456\n");
	/* 24 */
	check(fd3, "fd");
	/* 24 */
	check(fd1, "c\n");
	/* 24 */
	check(fd2, "789");
	/* 24 */
	check(fd3, NULL);
	/* 24 */
	check(fd1, "d");
	/* 24 */
	check(fd2, NULL);
	/* 24 */
	check(fd1, NULL);
	close(fd1);
	close(fd2);
	close(fd3);

	printf("\n[\033[1;35mNumber of tests: %d\033[0m]\n", count_test);
	printf("\033[1;35mby: joneves- \033[0m\n\n\n\n");
	return (0);
}