#include "get_next_line_bonus.h"

t_buffer    *add_new_buff(t_buffer **first, int fd)
{
    t_buffer	*res;
	t_buffer	*tmp;

	tmp = *first;
	res = malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	res->fd = fd;
	res->next = NULL;
    res->buff[0] = 0;
	if (*first == NULL)
		*first = res;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = res;
	}
	return (res);
}

t_buffer    *find_buff(t_buffer **first, int fd)
{
    t_buffer	*buffer;

	buffer = *first;
	while (buffer && buffer->fd != fd)
		buffer = buffer->next;
	if (buffer == NULL)
		buffer = add_new_buff(first, fd);
	return (buffer);
}

void	join(char **res, t_buffer *buffer)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, buffer->buff);
	if (tmp)
		free(tmp);
}

char	*read_line(t_buffer *buffer, int fd)
{
	ssize_t	read_int;
	char	*res;

	res = NULL;
	read_int = 0;
	join(&res, buffer);
	if (!contains_new_line(buffer->buff))
		read_int = read(fd, buffer->buff, BUFFER_SIZE);
	while (read_int && !contains_new_line(buffer->buff))
	{
		buffer->buff[read_int] = '\0';
		join(&res, buffer);
		read_int = read(fd, buffer->buff, BUFFER_SIZE);
	}
	if (read_int)
	{
		buffer->buff[read_int] = '\0';
		join(&res, buffer);
	}
	clean_buffer(buffer->buff);
	return (res);
}

char    *get_next_line(int fd)
{
    static t_buffer *first = NULL;
    t_buffer        *buff;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	    return (NULL);
    buff = find_buff(&first, fd);
    return (read_line(buff, fd));
}