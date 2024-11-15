/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:47:13 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/05 17:27:49 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

/*ft_printf.c*/
int	ft_printf(int fd, const char *format, ...);

/*ft_utils.c*/
int	pf_putaddr_fd(unsigned long addr, int fd);
int	pf_puthexa_fd(unsigned int num, char *hexa_digits, int fd);
int	pf_putstr_fd(char *s, int fd);
int	pf_putnbr_fd(int n, int fd);
int	pf_putunbr_fd(unsigned int n, int fd);

#endif
