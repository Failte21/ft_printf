/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:14:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 14:41:47 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned char	get_base(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'D' || c == 'U')
		return (10);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	return (0);
}

unsigned char	get_a(char c)
{
	if (c == 'X')
		return ('A');
	return ('a');
}

unsigned char	get_prefix(t_block *block)
{
	if (block->flag == 'p')
		return (ADDR_LITTLE);
	if (block->hashtag)
	{
		if (block->flag == 'x')
			return (ADDR_LITTLE);
		if (block->flag == 'X')
			return (ADDR_BIG);
		if (block->flag == 'o')
			return (FORCED_ZERO);
	}
	return (0);
}

void		get_flag_exceptions(t_block *block)
{
	block->fieldchar = block->minus ? ' ' : block->fieldchar;
	if (block->flag == 'c')
		block->precision = 0;
	if (block->fieldchar == '0' && block->precision >= 0 && block->flag != 'c')
		block->fieldchar = ' ';
	if (block->space)
		block->space -= (block->flag == 'u' || block->flag == 'U');
	if (block->plus)
		block->plus -= (block->flag == 'u' || block->flag == 'U');
}
