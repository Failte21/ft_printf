/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/21 11:37:03 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_functions(int (*p[127]) (va_list, t_block))
{
	/*p['s'] = fstr;*/
	/*p['p'] = fhexadress;*/
	p['d'] = fsigned_decimal;
	/*p['D'] = fsigned_decimal;*/
	/*p['i'] = fsigned_decimal;*/
	/*p['o'] = funsigned_octal;*/
	/*p['O'] = funsigned_octal;*/
	/*p['u'] = funsigned_decimal;*/
	/*p['U'] = funsigned_decimal;*/
	/*p['x'] = funsigned_hexa;*/
	/*p['X'] = funsigned_hexalarge;*/
	/*p['c'] = funsigned_char;*/
}

static int	get_fieldsize(t_block block)
{
	int	fieldsize;

	fieldsize = block.min_field != 0 ? block.min_field : block.space;
	return (fieldsize);
}

static int	flag_handler(int (*p[127]) (va_list, t_block), va_list ap, 
		t_block *block)
{
	block->fieldsize = get_fieldsize(*block);
	if (block->flag == '%')
	{
		block->fieldsize = ABS(block->fieldsize) < 1 ? 1 : block->fieldsize;
		if (block->fieldsize > 0)
			block->fieldsize = (print_field(1, block->fieldsize,
						block->fieldchar));
		ft_putchar('%');
		if (block->fieldsize < 0)
			block->fieldsize = (print_field(1, ABS(block->fieldsize),
						block->fieldchar));
		return (block->fieldsize);
	}
	return (*p[block->flag])(ap, *block);
}

int			display(t_block *first, va_list ap,
		int (*p[127]) (va_list, t_block))
{
	int				space;
	int				print_len;

	print_len = 0;
	while (first)
	{
		if (first->type == FLAG)
			print_len += flag_handler(p, ap, first);
		else
		{
			write(1, first->start, first->fieldsize);
			print_len += first->fieldsize;
		}
		first = first->next;
	}
	return (print_len);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int		(*p[127]) (va_list, t_block);
	t_block	*first;

	init_functions(p);
	if (!(first = new_block()))
		return (-1);
	if (parser(format, first) < 0)
		return (1);
	ft_putchar(first->flag);
	exit(1);
	va_start(ap, format);
	return (display(first, ap, p));
}
