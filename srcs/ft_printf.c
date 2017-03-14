/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 14:52:05 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	flag_handler(int (*p[127]) (va_list, t_block *), va_list ap, 
		t_block *block, unsigned char (*get_conversion[127])(t_block *block))
{
	/*printf("%c\n", block->fieldchar);*/
	/*printf("%d\n", block->minus);*/
	get_flag_exceptions(block);
	if (block->flag == '%')
	{
		block->datalen = 1;
		if (!block->minus)
			print_space(block);
		write(1, "%", 1);;
		if (block->minus)
			print_space(block);
		return (block->min_field > 1 ? block->min_field : 1);
	}
	block->conversion = get_conversion[block->flag](block);
	block->base = get_base(block->flag);
	block->a = get_a(block->flag);
	block->prefix = get_prefix(block);
	/*return (p[block->conversion](ap, block));*/
	/*exit(1);*/
	/*printf("%d\n", block->conversion);*/
	if (block->conversion < 9)
		return (p_unsigned(ap, block));
	if (block->conversion < 15)
		return (p_signed(ap, block));
	if (block->conversion < 17)
		return (p_char(ap, block));
	return (p_str(ap, block));
}

static int	display_str(t_block *block)
{
	if (block->len)
		write(1, block->start, block->len);
	return (block->len);
}

static int	display(t_block *first, va_list ap,
		int (*p[127]) (va_list, t_block *),
		unsigned char (*get_conversion[127])(t_block *block))
{
	int				space;
	int				print_len;
	t_block			*tmp;

	print_len = 0;
	while (first)
	{
		if (first->type == FLAG)
			print_len += flag_handler(p, ap, first, get_conversion);
		else
			print_len += display_str(first);
		tmp = first;
		first = first->next;
		free(tmp);
	}
	return (print_len);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int				(*p[127]) (va_list, t_block *);
	int				(*flags[127]) (t_block *, const char * restrict);
	unsigned char	(*get_conversion[127]) (t_block *);
	t_block	*first;

	if (!(*format))
		return (0);
	/*init_functions(p);*/
	init_flags_functions(flags);
	init_conversion(get_conversion);
	if (!(first = parser(format, flags, p)))
		return (1);
	va_start(ap, format);
	return (display(first, ap, p, get_conversion));
}
