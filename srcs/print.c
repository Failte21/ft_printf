/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:18:57 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/12 17:57:17 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	weird(t_block *block, uintmax_t n)
{
	if (n == 0 && block->precision >= 0)
	{
		if (block->flag == 'o' && block->hashtag)
			return (0);
		return (1);
	}
	return (0);
}

static void	fill_block_data(t_block *block, uintmax_t n)
{
	block->nb_len = get_len(n, block->base);
	block->nb_len -= weird(block, n);
	/*printf("%d\n", block->nb_len);*/
	/*printf("%d\n", block->precision);*/
	block->precision -= block->negative;
	block->datalen = get_data_len(block) + (block->precision >
			(block->nb_len - block->negative) && block->negative);
	/*printf("%d\n", block->datalen);*/
	block->min_field = block->min_field > block->datalen ? block->min_field :
		block->datalen;
	write(1, " ", (block->space && !(block->negative) && !(block->plus)));
}

int			print(uintmax_t n, t_block *block)
{
	fill_block_data(block, n);
	if (!block->minus)
		print_space(block);
	write(1, "+", block->plus - block->negative);
	write(1, "-", block->negative);
	if (block->precision >= 0)
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
	if (weird(block, n))
		return (block->min_field);
	else
		print_base(n, block->base, block->a);
	if (block->minus)
		print_space(block);
	return (block->min_field);
}
