/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:18:57 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 15:45:06 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print(uintmax_t n, t_block *block)
{
	block->nb_len = get_len(n, block->base);
	block->datalen = get_data_len(block) + (block->precision > 0 &&
			block->negative);
	block->min_field = block->min_field > block->datalen ? block->min_field :
		block->datalen;
	write(1, " ", (block->space && !(block->negative) && !(block->plus)));
	if (!block->minus)
		print_space(block);
	write(1, "+", block->plus - block->negative);
	write(1, "-", block->negative);
	if (block->precision < 0)
		return (0);
	print_precision(block->nb_len - block->negative, block->precision);
	if (n > 0)
		print_prefix(block->prefix);
	else
	{
		if (block->prefix > 0 && block->prefix < 3)
			block->min_field -= 2;
		else if (block->prefix > 0)
			block->min_field--;
	}
	if (block->minus && block->prefix > 0 && block->prefix < 3 &&
			block->fieldchar == '0')
		print_space(block);
	print_base(n, block->base, block->a);
	if (block->minus)
		print_space(block);
	return (block->min_field);
}
