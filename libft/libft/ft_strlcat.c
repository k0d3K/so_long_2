/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:27:06 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 20:59:49 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	size_dst = 0;
	size_src = 0;
	if (!dst && size == 0)
		return (0);
	while (*(dst + size_dst))
		size_dst++;
	while (*(src + size_src))
		size_src++;
	if (size <= size_dst)
		return (size_src + size);
	while (*(src + i) && i < size - size_dst - 1)
	{
		*(dst + size_dst + i) = *(src + i);
		i++;
	}
	*(dst + size_dst + i) = '\0';
	return (size_src + size_dst);
}
