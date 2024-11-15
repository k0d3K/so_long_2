/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:44:36 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/05 17:26:55 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(int fd, char c, va_list args)
{
	void	*addr;
	int		nb_char;

	nb_char = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (c == 's')
		nb_char = pf_putstr_fd(va_arg(args, char *), fd);
	else if (c == 'p')
	{
		addr = va_arg(args, char *);
		nb_char += pf_putaddr_fd((unsigned long)addr, fd);
	}
	else if (c == 'd' || c == 'i')
		nb_char = pf_putnbr_fd(va_arg(args, int), fd);
	else if (c == 'u')
		nb_char = pf_putunbr_fd((unsigned int)va_arg(args, int), fd);
	else if (c == 'x')
		nb_char = pf_puthexa_fd(va_arg(args, int), "0123456789abcdef", fd);
	else if (c == 'X')
		nb_char = pf_puthexa_fd(va_arg(args, int), "0123456789ABCDEF", fd);
	else
		ft_putchar_fd(c, 1);
	return (nb_char);
}

static int	is_valid(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	is_odd(const char *format)
{
	while (*(format + 1))
	{
		if (*format == '%' && is_valid(*(format + 1)))
			format++;
		else if (*format == '%' && !is_valid(*(format + 1)))
			return (1);
		format++;
	}
	return (0);
}

static int	is_percent_ok(const char *format)
{
	int	count_percent;

	count_percent = 0;
	while (*(format + 1))
		format++;
	if (*format == '%')
	{
		count_percent++;
		format--;
		while (*(format) == '%')
		{
			count_percent++;
			format--;
		}
	}
	return (count_percent % 2);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		nb_char;
	int		i;

	nb_char = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid(format[i + 1]))
			nb_char += print_format(fd, format[++i], args);
		else if (format[i] != '%' || format[i + 1] != 0 || is_odd(format))
		{
			ft_putchar_fd(format[i], fd);
			nb_char++;
		}
		i++;
	}
	va_end(args);
	if (format[i - 1] == '%' && is_percent_ok(format) && !is_odd(format))
		return (-1);
	return (nb_char);
}
