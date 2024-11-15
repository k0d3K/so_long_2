/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:49:21 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 22:07:20 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	size;

	if (!dest && !src)
		return (0);
	size = 0;
	while (size < n)
	{
		*(char *)(dest + size) = *(char *)(src + size);
		size++;
	}
	return (dest);
}
