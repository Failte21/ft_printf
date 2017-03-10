/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:47:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 15:32:30 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_unsigned_short(va_list ap, t_block *block)
{
	unsigned short	n;
	uintmax_t		ln;

	n = va_arg(ap, unsigned long);
	ln = (uintmax_t)n;
	return (print(ln, block));
}

int	print_unsigned_int(va_list ap, t_block *block)
{
	unsigned int	n;
	uintmax_t		ln;

	n = va_arg(ap, unsigned int);
	ln = (uintmax_t)n;
	return (print(ln, block));
}

int	print_unsigned_long(va_list ap, t_block *block)
{
	unsigned long	n;
	uintmax_t		ln;

	n = va_arg(ap, unsigned long);
	ln = (uintmax_t)n;
	return (print(ln, block));
}

int	print_unsigned_long_long(va_list ap, t_block *block)
{
	unsigned long	n;
	uintmax_t		ln;

	n = va_arg(ap, uintmax_t);
	ln = (uintmax_t)n;
	return (print(ln, block));
}

int	print_uintmax_t(va_list ap, t_block *block)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	return (print(n, block));
}

int	print_size_t(va_list ap, t_block *block)
{
	size_t		n;
	uintmax_t	ln;

	n = va_arg(ap, size_t);
	ln = (uintmax_t)n;
	return (print(ln, block));
}
