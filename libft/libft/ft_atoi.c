/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:31:03 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/08 22:05:06 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	number;
	int	count;

	sign = 1;
	number = 0;
	count = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*(nptr + count) >= '0' && *(nptr + count) <= '9')
		count++;
	while (count > 0)
	{
		number = 10 * number + (*(nptr++) - '0');
		count--;
	}
	return (sign * number);
}
