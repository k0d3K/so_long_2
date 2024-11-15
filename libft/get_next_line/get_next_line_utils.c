/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:55:51 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/11 14:28:12 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_bzero(void *s, size_t n)
// {
// 	size_t	size;

// 	size = 0;
// 	while (size < n)
// 		*(char *)(s + size++) = 0;
// 	return (s);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	size;

// 	size = 0;
// 	while (*s)
// 	{
// 		size++;
// 		s++;
// 	}
// 	return (size);
// }

int	fill_line(char *line, char **last_read)
{
	int	count;

	count = 0;
	while ((*last_read)[count])
	{
		line[count] = (*last_read)[count];
		if ((*last_read)[count++] == '\n')
			break ;
	}
	line[count] = 0;
	return (count);
}

char	*ft_strdup_free(char *src, int offset)
{
	int		count;
	int		size_src;
	char	*dest;

	count = 0;
	size_src = ft_strlen(src + offset);
	dest = (char *)malloc(sizeof(char) * (size_src + 1));
	if (!dest)
		return (NULL);
	while (src[count + offset])
	{
		dest[count] = src[count + offset];
		count++;
	}
	dest[count] = '\0';
	free(src);
	return (dest);
}

char	*ft_strdupcat_free(char *src_start, char *src_end)
{
	int		count;
	int		size_src_start;
	int		size_src_end;
	int		size;
	char	*dest;

	if (!src_start)
	{
		src_start = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		src_start[0] = 0;
	}
	count = 0;
	size = 0;
	size_src_start = ft_strlen(src_start);
	size_src_end = ft_strlen(src_end);
	dest = (char *)malloc(sizeof(char) * (size_src_start + size_src_end + 1));
	if (!dest)
		return (NULL);
	while (src_start[count])
		dest[size++] = src_start[count++];
	while (src_end[count - size_src_start])
		dest[size++] = src_end[count++ - size_src_start];
	dest[size] = '\0';
	free(src_start);
	return (dest);
}
