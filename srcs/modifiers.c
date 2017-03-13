/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 09:24:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/13 12:24:56 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	modifier_h(t_block *block, const char *restrict s)
{
	if (s[1] && s[1] == 'h')
	{
		block->modifier = block->modifier < HH ? HH : block->modifier;
		return (2);
	}
	block->modifier = block->modifier < H ? H : block->modifier;
	return (1);
}

int	modifier_j(t_block *block, const char *restrict s)
{
	block->modifier = block->modifier < J ? J : block->modifier;
	return (1);
}

int	modifier_l(t_block *block, const char *restrict s)
{
	if (s[1] && s[1] == 'l')
	{
		block->modifier = block->modifier < LL ? LL : block->modifier;
		return (2);
	}
	block->modifier = block->modifier < L ? L : block->modifier;
	return (1);
}

int	modifier_z(t_block *block, const char *restrict s)
{
	block->modifier = block->modifier < Z ? Z : block->modifier;
	return (1);
}
