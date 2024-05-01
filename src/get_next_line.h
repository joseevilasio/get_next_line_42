/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:21:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/05/01 01:01:29 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/* Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred */
char	*get_next_line(int fd);
char	*ft_putcache(char *buffer, char *cache, char *content, int read_size);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);

#endif //GET_NEXT_LINE_H
