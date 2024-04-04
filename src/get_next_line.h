/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josejunior <josejunior@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:09:36 by josejunior        #+#    #+#             */
/*   Updated: 2024/04/04 19:16:24 by josejunior       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/* params: fd-> The file descriptor to read from.
Return value Read line: correct behavior NULL: there is nothing else to read, 
or an error occurred. */
char			*get_next_line(int fd);
char			*ft_get_line(char *content);
unsigned int	ft_line_len(const char *str);
char			*ft_read_fd(int fd);
#endif //GET_NEXT_LINE_H
