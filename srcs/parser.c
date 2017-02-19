/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:18:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/18 23:01:03 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_block	new_block(const char * restrict start, char type,
		char space_before)
{
	t_block	new;

	new.start = (char *)start;
	new.space_before = space_before;
	new.space_after = 0;
	new.len = 0;
	new.type = type;
	return (new);
}

int				parser(const char * restrict s, t_block blocks[500])
{
	unsigned int	j;
	const char		* restrict sc;
	unsigned char	space;

	j = 0;
	sc = s;
	while (*s)
	{
		space = 0;
		if (*s == '%')
		{
			s++;
			while (*s == ' ')
			{
				space = 1;
				s++;
			}
			if (error_handler(*s))
				return (-1);
			space = *s == '%' ? 0 : space;
			blocks[j] = new_block(NULL, SPECIFIER, space);
			blocks[j].specifier = *s;
			j++;
			s++;
		}
		else
		{
			blocks[j] = new_block(s, STR, 0); 
			while (*s && *s != '%')
			{
				blocks[j].len++;
				s++;
			}
			j++;
		}
	}
	return (j);
}
