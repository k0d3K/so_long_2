/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:51:14 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:56 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	while (ptr != (char *)s)
		if (*(ptr--) == (unsigned char)c)
			return (++ptr);
	if (*ptr == (unsigned char)c)
		return (ptr);
	return (0);
}
