/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:07:14 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/11 09:19:38 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	fill(char *res, char const *s, unsigned int offset)
{
	unsigned int	i;

	i = 0;
	while (*(s + i))
	{
		*(res + offset + i) = *(s + i);
		i++;
	}
	*(res + offset + i) = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size_s1;
	unsigned int	size_s2;
	char			*res;

	if (!s1 || !s2)
		return (0);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!res)
		return (0);
	fill(res, s1, 0);
	fill(res, s2, size_s1);
	return (res);
}
