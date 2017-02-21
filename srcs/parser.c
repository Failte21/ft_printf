/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:18:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/21 11:33:20 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		is_flag(char c)
{
	return (c == ' ' || c == '0' || c == '+' || c == '-');
}

static int		get_strblock(const char * restrict s, t_block *block,
		int (*f_flags[127]) (t_block *, const char * restrict))
{
	unsigned int i;

	i = 0;
	block->start = (char *)s;
	block->type = STR; 
	while (s[i] && s[i] != '%')
	{
		block->fieldsize++;
		i++;
	}
	return (i);
}

static int		get_flags(const char * restrict s, t_block *current,
		int (*f_flags[127]) (t_block *, const char * restrict))
{
	unsigned int i;

	i = 1;
	/*while (is_flag(s[i]))*/
		/*i += (f_flags[s[i]])(block, s + i);*/
	/*if (ft_isdigit(s[i]) || s[i] == '-')*/
	/*{*/
		/*block->min_field = ft_atoi(s + i);*/
		/*i += ft_nblen(block->min_field, 10);*/
	/*}*/
	if (error_handler(s[i]) < 0)
		return(-1);
	current->flag = s[i];
	return (i + 1);
}

int				parser(const char * restrict s, t_block *first)
{
	const char		* restrict sc;
	int				(*f_flags[127]) (t_block *, const char * restrict);
	t_block			*current;

	sc = s;
	current = first;
	init_f_flags(f_flags);
	while (*sc)
	{
		if (*sc == '%')
		{
			if ((sc += get_flags(sc, current, f_flags)) < 0)
				return (-1);
		}
		else
			sc += get_strblock(sc, current, f_flags);
		current = current->next;
		if (*sc)
			if (!(current = new_block()))
				return (-1);
	}
	return (1);
}
