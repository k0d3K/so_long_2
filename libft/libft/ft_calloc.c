/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:49:32 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/09 12:32:37 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size && nmemb > 2147483647 / size)
		return (0);
	result = (void *)malloc(size * nmemb);
	if (!result)
		return (0);
	ft_bzero(result, nmemb * size);
	return (result);
}
