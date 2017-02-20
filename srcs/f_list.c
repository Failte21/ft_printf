/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:02:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/19 18:53:10 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_field(int len, int fieldsize, char fieldchar)
{
	while (len < fieldsize)
	{
		write(1, &fieldchar, 1);
		len++;
	}
	return (len);
}

int	fstr(va_list ap, t_block block)
{
	char			*s;
	unsigned int	len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	block.fieldsize = ABS(block.fieldsize) < len ? len : block.fieldsize;
	if (block.fieldsize > 0)
		block.fieldsize = (print_field(len, block.fieldsize, block.fieldchar));
	ft_putstr(s);
	if (block.fieldsize < 0)
		block.fieldsize = (print_field(len, ABS(block.fieldsize),
					block.fieldchar));
	return (block.fieldsize);
}

int	fsigned_decimal(va_list ap, t_block block)
{
	signed int	d;
	unsigned int	len;

	d = va_arg(ap, int);
	len = ft_nblen(d, 10);
	block.fieldsize = ABS(block.fieldsize) < len ? len : block.fieldsize;
	if (block.fieldsize > 0)
		block.fieldsize = (print_field(len, block.fieldsize, block.fieldchar));
	ft_putnbr(d);
	if (block.fieldsize < 0)
		block.fieldsize = (print_field(len, ABS(block.fieldsize),
					block.fieldchar));
	return (block.fieldsize);
}

int	funsigned_char(va_list ap, t_block block)
{
	unsigned char	c;

	c = va_arg(ap, int);
	block.fieldsize = ABS(block.fieldsize) < 1 ? 1 : block.fieldsize;
	if (block.fieldsize > 0)
		block.fieldsize = (print_field(1, block.fieldsize, block.fieldchar));
	ft_putchar(c);
	if (block.fieldsize < 0)
		block.fieldsize = (print_field(1, ABS(block.fieldsize),
					block.fieldchar));
	return (block.fieldsize);
}

int	fhexadress(va_list ap, t_block block)
{
	int				nb;
	unsigned int	len;

	nb = va_arg(ap, int);
	len = ft_nblen(nb, 10);
	block.fieldsize = ABS(block.fieldsize) < len ? len : block.fieldsize;
	if (block.fieldsize > 0)
		block.fieldsize = (print_field(len, block.fieldsize, block.fieldchar));
	ft_putstr("0x10");
	print_unsigned_base(nb, 16, 'a');
	if (block.fieldsize < 0)
		block.fieldsize = (print_field(len, ABS(block.fieldsize),
					block.fieldchar));
	return (block.fieldsize);
}

/*
int	funsigned_octal(va_list ap, t_block block)
{
	unsigned int	o;

	o = va_arg(ap, int);
	print_unsigned_base(o, 8, 'a');
	return (ft_nblen(o, 8));
}

int	funsigned_decimal(va_list ap, t_block block)
{
	unsigned int	n;

	n = va_arg(ap, int);
	ft_putnbr(n);
	return (ft_nblen(n, 10));
}

int	funsigned_hexa(va_list ap, t_block block)
{
	unsigned int	hex;

	hex = va_arg(ap, int);
	print_unsigned_base(hex, 16, 'a');
	return (ft_nblen(hex, 16));
}

int	funsigned_hexalarge(va_list ap, t_block block)
{
	unsigned int	hex;

	hex = va_arg(ap, int);
	print_unsigned_base(hex, 16, 'A');
	return (ft_nblen(hex, 16));
}
*/
