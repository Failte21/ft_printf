/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:11:03 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 14:29:45 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned char	char_conversion(t_block *block)
{
	if ((block->modifier == 'l' && block->flag == 'c') || block->flag == 'C')
		return (WCHAR_T);
	if ((block->modifier == 'l' && block->flag == 's') || block->flag == 'S')
		return (WCHAR_TT);
	if (block->flag == 'c')
		return (CHAR);
	return (STR_FLAG);
}

unsigned char	signed_conversion(t_block *block)
{
	if (block->modifier == H)
		return (SHORT);
	if (block->modifier == HH)
		return (SIGNED_CHAR);
	if (block->modifier == L)
		return (LONG);
	if (block->modifier == LL)
		return (LONG_LONG);
	if (block->modifier == J)
		return (INTMAX_T);
	if (block->modifier == Z)
		return (SSIZE_T);
	return (14);
}

unsigned char	unsigned_conversion(t_block *block)
{
	if (block->modifier == H)
	{
		if (block->flag == 'U')
			return (UNSIGNED_LONG);
		return (UNSIGNED_SHORT);
	}
	if (block->modifier == HH)
		return (UNSIGNED_CHAR);
	if (block->modifier == L || block->flag == 'p' || block->flag == 'U' ||
			block->flag == 'O')
		return (UNSIGNED_LONG);
	if (block->modifier == LL)
		return (UNSIGNED_LONG_LONG);
	if (block->modifier == J)
		return (UINTMAX_T);
	if (block->modifier == Z)
		return (SIZE_T);
	return (3);
}

unsigned char	unsigned_long_conversion(t_block *block)
{
	return (UNSIGNED_LONG);
}

unsigned char	signed_long_conversion(t_block *block)
{
	return (LONG);
}
