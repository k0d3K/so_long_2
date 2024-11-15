/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:27:10 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/08 20:17:24 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
		if (*(ptr++) == (unsigned char)c)
			return (--ptr);
	if (*ptr == (unsigned char)c)
		return (ptr);
	return (0);
}
