/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:57:48 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/11/26 17:01:19 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void	join(char **res, char *buffer);
char	*read_line(char *buffer, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		contains_new_line(char *str);
void	clean_buffer(char *buffer);
char	*ft_strjoin(char *final, char *buffer);

#endif
