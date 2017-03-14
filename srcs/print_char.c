/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:47:48 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 14:38:32 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_char(char c, t_block *block)
{
	/*signed char c;*/

	/*c = va_arg(ap, signed int);*/
	block->precision = c == 0 ? 0 : block->precision;
	block->nb_len = 1;
	block->datalen = get_data_len(block);
	block->datalen -= block->space;
	block->min_field = block->min_field > block->datalen ? block->min_field :
		block->datalen;
	/*printf("%c\n", block->fieldchar);*/
	if (!block->minus)
		print_space(block);
	ft_putchar(c);
	if (block->minus)
		print_space(block);
	return (block->min_field);
}

int		print_unsigned_char(va_list ap, t_block *block)
{
	unsigned char c;

	c = va_arg(ap, unsigned int);
	block->nb_len = 1;
	block->datalen = get_data_len(block);
	block->min_field = block->min_field > block->datalen ? block->min_field :
		block->datalen;
	write(1, " ", block->space);
	if (!block->minus)
		print_space(block);
	if (c == 0 || c == UCHAR_MAX)
	{
		print_base(c, block->base, block->a);
		return (ft_nblen(c, 10));
	}
	ft_putchar(c);
	if (!block->minus)
		print_space(block);
	return (block->min_field);
}

int		print_str(char *s, t_block *block)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	block->nb_len = ft_strlen(s);
	if (block->precision > 0)
		block->nb_len = block->nb_len > block->precision ? block->precision :
			block->nb_len;
	block->datalen = get_str_len(block);
	block->min_field = block->min_field > block->datalen ? block->min_field :
		block->datalen;
	if (!block->minus)
		print_space(block);
	write(1, s, block->nb_len);
	if (block->minus)
		print_space(block);
	return (block->min_field);
}
