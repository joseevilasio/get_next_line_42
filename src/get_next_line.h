/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:21:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/01 23:33:14 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif //BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/* Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred */
char	*get_next_line(int fd);

/* Utils */

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif //GET_NEXT_LINE_H
