/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig, <lguerbig@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:43:08 by lguerbig,         #+#    #+#             */
/*   Updated: 2024/10/10 00:36:41 by lguerbig,        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	size;
	char			*res;

	if (f == 0 || s == 0)
		return (0);
	size = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	index = 0;
	while (index < size)
	{
		res[index] = (*f)(index, s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
