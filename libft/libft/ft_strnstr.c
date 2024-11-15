/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:31:06 by lguerstr          #+#    #+#             */
/*   Updated: 2024/10/10 21:32:04 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size_little;

	i = 0;
	size_little = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && little[j] && big[i + j] == little[j])
			j++;
		if (j == size_little)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
