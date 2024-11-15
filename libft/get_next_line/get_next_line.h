/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:55:45 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/11 14:27:35 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*get_next_line.c*/
char	*find_line(char *line, char **last_read, int nb_read);
int		read_from_fd(char *buffer, char **line, char **last_read, int fd);
char	*read_line(char *line, int size_line, char **last_read, int fd);
char	*get_next_line(int fd);
char	*clean(char *line, char *buffer, char **last_read);

/*get_next_line_utils.c*/
//void	*ft_bzero(void *s, size_t n);
//size_t	ft_strlen(const char *s);
int		fill_line(char *line, char **last_read);
char	*ft_strdup_free(char *src, int offset);
char	*ft_strdupcat_free(char *src_start, char *src_end);

#endif
