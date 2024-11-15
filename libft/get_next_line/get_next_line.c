/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:50:00 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/11 14:19:41 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_line(char *line, char **last_read, int nb_read)
{
	int	count;

	count = 0;
	while ((*last_read)[count] && (*last_read)[count] != '\n')
		count++;
	if ((*last_read)[count] == '\n' || !nb_read)
	{
		free(line);
		line = (char *)malloc(sizeof(char)
				* (count + 1 + !!(*last_read)[count]));
		if (!line)
			return (NULL);
		count = fill_line(line, last_read);
		*last_read = ft_strdup_free(*last_read, count);
		if (!*last_read)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

int	read_from_fd(char *buffer, char **line, char **last_read, int fd)
{
	int	nb_read;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read < 0 || (nb_read == 0 && (!*last_read || !**last_read)))
		return (-1);
	else if (nb_read > 0)
	{
		*last_read = ft_strdupcat_free(*last_read, buffer);
		if (!*last_read)
			return (-1);
	}
	if (*last_read)
	{
		*line = find_line(*line, last_read, nb_read);
		if (!*line)
			return (-1);
	}
	return (nb_read);
}

char	*clean(char *line, char *buffer, char **last_read)
{
	free(line);
	free(buffer);
	free(*last_read);
	*last_read = 0;
	return (NULL);
}

char	*read_line(char *line, int size_line, char **last_read, int fd)
{
	char	*buffer;
	int		nb_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (clean(line, buffer, last_read));
	nb_read = 1;
	while ((!size_line || line[size_line - 1] != '\n') && nb_read > 0)
	{
		nb_read = read_from_fd(buffer, &line, last_read, fd);
		if (nb_read == -1)
			return (clean(line, buffer, last_read));
		size_line = ft_strlen(line);
	}
	free(buffer);
	if (nb_read == 0 && !**last_read)
	{
		free(*last_read);
		*last_read = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last_read[1024];
	char		*line;
	int			size_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	ft_bzero(line, BUFFER_SIZE + 1);
	size_line = 0;
	line = read_line(line, size_line, &last_read[fd], fd);
	if (!line)
		return (NULL);
	return (line);
}
