/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:23:04 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/09 12:48:27 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		count;
	int		size_src;
	char	*dest;

	count = 0;
	size_src = 0;
	while (s[size_src])
		size_src++;
	dest = (char *)malloc(size_src * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (s[count])
	{
		dest[count] = s[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
