/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:19:05 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/17 19:45:38 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putaddr_fd(unsigned long addr, int fd)
{
	char	*hexa_digits;
	char	buffer[16];
	int		nb_char;
	int		i;

	i = 0;
	hexa_digits = "0123456789abcdef";
	nb_char = 0;
	if (addr == 0)
	{
		nb_char = pf_putstr_fd("(nil)", fd);
		return (nb_char - 1);
	}
	while (addr > 0)
	{
		buffer[i++] = hexa_digits[addr % 16];
		addr /= 16;
	}
	nb_char += i - 1 + pf_putstr_fd("0x", fd);
	while (i > 0)
		ft_putchar_fd(buffer[--i], fd);
	return (nb_char);
}

int	pf_puthexa_fd(unsigned int num, char *hexa_digits, int fd)
{
	char	buffer[8];
	int		nb_char;
	int		i;

	i = 0;
	nb_char = 0;
	if (num == 0)
	{
		nb_char = pf_putstr_fd("0", fd);
		return (nb_char);
	}
	while (num > 0)
	{
		buffer[i++] = hexa_digits[num % 16];
		num /= 16;
	}
	nb_char += i;
	while (i > 0)
		ft_putchar_fd(buffer[--i], fd);
	return (nb_char);
}

int	pf_putstr_fd(char *s, int fd)
{
	int	nb_char;

	if (!s)
	{
		nb_char = pf_putstr_fd("(null)", fd);
		return (nb_char);
	}
	nb_char = 0;
	while (s[nb_char])
	{
		ft_putchar_fd(s[nb_char], fd);
		nb_char++;
	}
	return (nb_char);
}

int	pf_putnbr_fd(int n, int fd)
{
	int	nb_char;

	nb_char = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		nb_char = 11;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb_char++;
		n = -n;
	}
	if (n / 10 > 0)
		nb_char += pf_putnbr_fd(n / 10, fd);
	if (n >= 0)
	{
		ft_putchar_fd(n % 10 + '0', fd);
		nb_char++;
	}
	return (nb_char);
}

int	pf_putunbr_fd(unsigned int n, int fd)
{
	int	nb_char;

	nb_char = 0;
	if (n / 10 > 0)
		nb_char += pf_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	nb_char++;
	return (nb_char);
}
