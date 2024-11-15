/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:11:38 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/08 20:04:49 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	size;

	size = 0;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (size < n)
		{
			*(char *)(dest + size) = *(char *)(src + size);
			size++;
		}
	}
	else
	{
		while (size < n)
		{
			*(char *)(dest + n - size - 1) = *(char *)(src + n - size - 1);
			size++;
		}
	}
	return (dest);
}
