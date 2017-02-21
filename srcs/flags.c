/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:50:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/20 17:45:04 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_space(t_block *block, const char * restrict s)
{
	unsigned int	i;

	i = 0;
	if (!block->space)
		block->space = 1;
	while (s[i] == ' ')
		i++;
	return (i);
}

int		flag_zero(t_block *block, const char * restrict s)
{
	unsigned int i;

	i = 0;
	block->zero = 1;
	while (s[i] == '0')
		i++;
	return (i);
}

int		flag_minus(t_block *block, const char * restrict s)
{
	unsigned int i;

	i = 0;
	block->minus = 1;
	while (s[i] == '-')
		i++;
	return (i);
}

int		flag_plus(t_block *block, const char * restrict s)
{
	unsigned int i;

	i = 0;
	block->plus = 1;
	while (s[i] == '-')
		i++;
	return (i);
}

int		flag_hashtag(t_block *block, const char * restrict s)
{
	unsigned int i;

	i = 0;
	block->hashtag = 1;
	while (s[i] == '-')
		i++;
	return (i);
}
