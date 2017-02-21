/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:31:51 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/21 11:36:17 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_block			*new_block(void)
{
	t_block *block;

	if (!(block = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	block->fieldsize = 0;
	block->plus = 0;
	block->minus = 0;
	block->hashtag = 0;
	block->zero = 0;
	block->space = 0;
	block->next = NULL;
	return (block);
}

void		init_f_flags(
		int (*f_flags[127]) (t_block *, const char * restrict))
{
	f_flags['-'] = flag_minus;
	f_flags['0'] = flag_zero;
	f_flags['+'] = flag_plus;
	f_flags[' '] = flag_space;
	f_flags['#'] = flag_hashtag;
}
