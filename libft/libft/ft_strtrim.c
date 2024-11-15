/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:31 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 21:09:09 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char const c)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*res;

	start = 0;
	if (!s1 || !set)
		return (0);
	while (s1[start] && is_in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(set, s1[end - 1]))
		end--;
	res = ft_substr(s1, start, end - start);
	return (res);
}
