/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 10:00:48 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 17:10:25 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_space(t_block *block)
{
	/*printf("%d\n", block->min_field);*/
	/*exit(1);*/
	if (!block->minus && block->prefix > 0 && block->prefix < 3 &&
			block->fieldchar == '0')
	{
		block->minus = 1;
		return ;
	}
	if (block->minus && block->prefix > 0 && block->prefix < 3 &&
			block->fieldchar == '0')
		block->minus = 0;
	if (block->fieldchar == '0')
	{
		write(1, "+", block->plus - block->negative);
		write(1, "-", block->negative);
		block->plus = 0;
		block->negative = 0;
	}
	while (block->datalen++ < block->min_field)
		write(1, &(block->fieldchar), 1);
}

void	print_precision(unsigned int datalen, unsigned int precision)
{
	while (datalen++ < precision)
		write(1, "0", 1);
}

void	print_prefix(unsigned char c)
{
	if (c == ADDR_LITTLE)
		write(1, "0x", 2);
	if (c == ADDR_BIG)
		write(1, "0X", 2);
	if (c == FORCED_ZERO)
		write(1, "0", 1);
}
