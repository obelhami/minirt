/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:23:54 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/20 16:43:35 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_get_next_line(char *line);
char	*ft_get_line(char *line, int fd);
char	*new_line(char *line);
char	*ft_ft_strjoin(char *s1, const char *s2);
char	*ft_strchr(const char *str, int find);
size_t	ft_strlen(const char *tab);

#endif
