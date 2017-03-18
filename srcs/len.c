/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 09:46:00 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 18:18:29 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	get_len(uintmax_t nb, unsigned char base)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

unsigned int	get_data_len(t_block *block)
{
	unsigned int data_len;

	data_len = block->nb_len;
	if (block->plus && !block->negative)
		data_len++;
	data_len += block->negative;
	if (!block->negative && !block->plus)
		data_len += block->space;
	data_len += (block->prefix == ADDR_LITTLE || block->prefix == ADDR_BIG) * 2;
	data_len += block->prefix == FORCED_ZERO;
	/*printf("%d\n", data_len);*/
	if (block->precision > block->nb_len)
		data_len += block->precision - block->nb_len;
	/*printf("%d\n", data_len);*/
	return (data_len);
}

unsigned int	get_str_len(t_block *block)
{
	unsigned int data_len;

	data_len = block->nb_len;
	data_len += block->plus;
	data_len += block->space;
	return (data_len);
}
