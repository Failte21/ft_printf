/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:48:33 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 10:51:27 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_short(va_list ap, t_block *block)
{
	short		n;
	uintmax_t	ln;

	n = va_arg(ap, int);
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	block->negative = n < 0;
	return (print(ln, block));
}

int	print_signed_char(va_list ap, t_block *block)
{
	signed char	n;
	uintmax_t	ln;

	n = va_arg(ap, int);
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	block->negative = n < 0;
	return (print(ln, block));
}

int	print_signed_int(va_list ap, t_block *block)
{
	signed int	n;
	uintmax_t	ln;

	n = va_arg(ap, signed int);
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	block->negative = n < 0;
	/*printf("%d\n", block->negative);*/
	/*exit(1);*/
	return (print(ln, block));
}

int	print_long(va_list ap, t_block *block)
{
	long		n;
	uintmax_t	ln;

	n = va_arg(ap, long);
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	block->negative = n < 0;
	return (print(ln, block));
}

int	print_long_long(va_list ap, t_block *block)
{
	long long	n;
	uintmax_t	ln;

	n = va_arg(ap, long long);
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	block->negative = n < 0;
	return (print(ln, block));
}

int	print_intmax_t(va_list ap, t_block *block)
{
	intmax_t	n;
	uintmax_t	ln;

	n = va_arg(ap, intmax_t);
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	block->negative = n < 0;
	return (print(ln, block));
}

int	print_ssize_t(va_list ap, t_block *block)
{
	intmax_t	n;
	uintmax_t	ln;
	size_t		sn;

	n = va_arg(ap, intmax_t);
	sn = n < 0 ? 0 : n;
	ln = (uintmax_t)sn;
	return (print(ln, block));
}
