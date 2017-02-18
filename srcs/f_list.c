/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:02:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/17 14:15:37 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	fstr(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr(s);
	return (ft_strlen(s));
}

int	fsigned_decimal(va_list ap)
{
	signed int	d;

	d = va_arg(ap, int);
	ft_putnbr(d);
	return (ft_nblen(d, 10));
}

int	funsigned_char(va_list ap)
{
	unsigned char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int	fhexadress(va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	ft_putstr("0x10");
	ft_putnbr_base(nb, 16, 'a');
	return (ft_nblen(nb, 16));
}

int	funsigned_octal(va_list ap)
{
	unsigned int	o;

	o = va_arg(ap, int);
	ft_putnbr_base(o, 8, 'a');
	return (ft_nblen(o, 8));
}

int	funsigned_decimal(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, int);
	ft_putnbr(n);
	return (ft_nblen(n, 10));
}

int	funsigned_hexa(va_list ap)
{
	unsigned int	hex;

	hex = va_arg(ap, int);
	ft_putnbr_base(hex, 16, 'a');
	return (ft_nblen(hex, 16));
}

int	funsigned_hexalarge(va_list ap)
{
	unsigned int	hex;

	hex = va_arg(ap, int);
	ft_putnbr_base(hex, 16, 'A');
	return (ft_nblen(hex, 16));
}
