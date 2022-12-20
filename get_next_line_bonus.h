#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_buffer
{
    int     fd;
    char    buff[BUFFER_SIZE];
    struct s_buffer *next;
} t_buffer;

t_buffer    *find_buff(t_buffer **first, int fd);
t_buffer    *add_new_buff(t_buffer **first, int fd);
void	join(char **res, t_buffer *buffer);
char	*read_line(t_buffer *buffer, int fd);
char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
int	contains_new_line(char *str);
void	clean_buffer(char *buffer);
char	*ft_strjoin(char *final, char *buffer);

#endif