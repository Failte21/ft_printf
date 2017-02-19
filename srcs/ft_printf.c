/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/18 23:18:00 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_functions(int (*p[127]) (va_list))
{
	p['s'] = fstr;
	p['p'] = fhexadress;
	p['d'] = fsigned_decimal;
	p['D'] = fsigned_decimal;
	p['i'] = fsigned_decimal;
	p['o'] = funsigned_octal;
	p['O'] = funsigned_octal;
	p['u'] = funsigned_decimal;
	p['U'] = funsigned_decimal;
	p['x'] = funsigned_hexa;
	p['X'] = funsigned_hexalarge;
	p['c'] = funsigned_char;
}

static int	specifier_handler(int (*p[127]) (va_list), va_list ap, 
		t_block block)
{
	if (block.specifier == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (*p[block.specifier])(ap);
}

int			display(t_block blocks[500], int len, va_list ap,
		int (*p[127]) (va_list))
{
	int				i;
	unsigned int	space;
	int				print_len;

	i = -1;
	while (++i < len)
	{
		print_len += (blocks[i].space_before + blocks[i].space_after); 
		space = 0;
		while (space++ < blocks[i].space_before)
			write(1, " ", 1);
		if (blocks[i].type == SPECIFIER)
			print_len = specifier_handler(p, ap, blocks[i]);
		else
		{
			write(1, blocks[i].start, blocks[i].len);
			print_len += blocks[i].len;
		}
		space = 0;
		while (space++ < blocks[i].space_after)
			write(1, " ", 1);
	}
	return (print_len);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int		(*p[127]) (va_list);
	t_block	blocks[500];
	int		array_len;

	if ((array_len = parser(format, blocks)) < 0)
		return (1);
	init_functions(p);
	va_start(ap, format);
	return (display(blocks, array_len, ap, p));
}
