/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:47:38 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/18 09:16:33 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_str(int n)
{
	int		size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	fill_str(char *str, int n, int size)
{
	int		count;
	int		neg;

	count = 0;
	neg = 0;
	if (n < 0)
	{
		str[count] = '-';
		n = -n;
		neg = 1;
	}
	while (count + neg < size)
	{
		str[size - 1 - count++] = n % 10 + 48;
		n = n / 10;
	}
	str[count + neg] = 0;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	size = size_str(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	fill_str(str, n, size);
	return (str);
}
