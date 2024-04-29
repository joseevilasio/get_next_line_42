/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:21:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/04/28 23:32:55 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred */
char	*get_next_line(int fd);
size_t	read_line(int fd, char *buffer, size_t size_buffer);

#endif //GET_NEXT_LINE_H
