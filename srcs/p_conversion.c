/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:43:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 14:51:51 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_signed(va_list ap, t_block *block)
{
	intmax_t	n;
	uintmax_t	ln;

	n = va_arg(ap, intmax_t);
	if (block->conversion == SIGNED_CHAR)
		n = (char)n;
	if (block->conversion == SHORT)
		n = (short)n;
	if (block->conversion == SIGNED_INT)
		n = (signed int)n;
	if (block->conversion == LONG)
		n = (long)n;
	if (block->conversion == LONG_LONG)
		n = (long long)n;
	/*printf("%jd\n", n);*/
	/*exit(1);*/
	block->negative = n < 0;
	ln = n > 0 ? (uintmax_t)n : (uintmax_t)-n;
	return (print(ln, block));
}

int		p_unsigned(va_list ap, t_block *block)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	/*printf("hello : %ju\n", n);*/
	/*exit(1);*/
	if (block->conversion == UNSIGNED_CHAR)
		n = (unsigned char)n;
	if (block->conversion == UNSIGNED_SHORT)
		n = (unsigned short)n;
	if (block->conversion == UNSIGNED_INT)
		n = (unsigned int)n;
	if (block->conversion == UNSIGNED_LONG)
		n = (unsigned long)n;
	if (block->conversion == UNSIGNED_LONG_LONG)
		n = (unsigned long long)n;
	if (block->conversion == SIZE_T)
		n = (size_t)n;
	return (print(n, block));
}

int		p_char(va_list ap, t_block *block)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	if (block->conversion == CHAR)
		return (print_char((char)n, block));
	if (block->conversion == WCHAR_T)
		return (u_charr((char)n, block));
	return (0);
}

int		p_str(va_list ap, t_block *block)
{
	char	*s;
	wchar_t	*ws;

	if (block->conversion == STR_FLAG)
	{
		s = va_arg(ap, char *);
		return (print_str(s, block));
	}
	if (block->conversion == WCHAR_TT)
	{
		ws = va_arg(ap, wchar_t *);
		return (u_str(ws, block));
	}
	return (0);
}
