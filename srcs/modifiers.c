/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 09:24:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/08 17:48:50 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	modifier_h(t_block *block, const char *restrict s)
{
	if (s[1] && s[1] == 'h')
	{
		block->modifier = HH;
		return (2);
	}
	block->modifier = H;
	return (1);
}

int	modifier_j(t_block *block, const char *restrict s)
{
	block->modifier = J;
	return (1);
}

int	modifier_l(t_block *block, const char *restrict s)
{
	if (s[1] && s[1] == 'l')
	{
		block->modifier = LL;
		return (2);
	}
	block->modifier = L;
	return (1);
}

int	modifier_z(t_block *block, const char *restrict s)
{
	block->modifier = Z;
	return (1);
}
