/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:17:06 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 16:12:19 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_precision(t_block *block, const char *restrict s)
{
	unsigned int	i;

	i = 1;
	block->precision = ft_atoi(s + i);
	/*block->precision = block->precision > 0 ? block->precision : -1;*/
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}
