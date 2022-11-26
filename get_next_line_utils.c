/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaydamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:57:58 by dhaydamo          #+#    #+#             */
/*   Updated: 2022/11/26 16:57:59 by dhaydamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	contains_new_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*ft_strjoin(char *final, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (buffer[0] == 0)
		return (NULL);
	if (final == NULL)
		res = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	else
		res = malloc(sizeof(char) * (ft_strlen(final) + ft_strlen(buffer) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (final && final[i])
		res[j++] = final[i++];
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		res[j++] = buffer[i++];
	if (buffer[i] == '\n')
		res[j++] = '\n';
	res[j] = '\0';
	return (res);
}
