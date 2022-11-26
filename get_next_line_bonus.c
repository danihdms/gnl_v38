/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:57:11 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/11/26 16:57:13 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	join(char **res, char *buffer)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, buffer);
	if (tmp)
		free(tmp);
}

char	*read_line(char *buffer, int fd)
{
	ssize_t	read_int;
	char	*res;

	res = NULL;
	read_int = 0;
	join(&res, buffer);
	if (!contains_new_line(buffer))
		read_int = read(fd, buffer, BUFFER_SIZE);
	while (read_int && !contains_new_line(buffer))
	{
		buffer[read_int] = '\0';
		join(&res, buffer);
		read_int = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_int)
	{
		buffer[read_int] = '\0';
		join(&res, buffer);
	}
	clean_buffer(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	return (read_line(buffer[fd], fd));
}
